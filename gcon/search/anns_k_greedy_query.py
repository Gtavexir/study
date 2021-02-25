import sys
import random
from tqdm import tqdm
import heapq
from collections import namedtuple
import time


MAXINT = 2 ** 31 - 1

Candidate = namedtuple('Candidate', ['distance', 'id'])


def euclidean_distance(vec_a, vec_b):
    s = 0
    for a, b in zip(vec_a, vec_b):
        s += (a - b) ** 2

    return s ** 0.5

def cosine_distance(vec_a, vec_b):

    ab = (sum(a ** 2 for a in vec_a) * sum(b ** 2 for b in vec_b)) ** 0.5
    if ab == 0:
        return 0
    a_dot_b = sum( a * b for a, b in zip(vec_a, vec_b))
    return 1-(a_dot_b / ab)

def dist(vec_a, vec_b, metric):

    if metric == 'e':
        return euclidean_distance(vec_a, vec_b)
    elif metric == 'c':
        return cosine_distance(vec_a, vec_b)


class ANNS:

    def __init__(self, data_path, graph_path, query_path):
        #print("loading data...")
        data = [self.parse_line(line) for line in open(data_path, 'r', encoding='UTF8')]
        #print("loading vector complete.")
        self.D = [d[1] for d in data]  # vectors
        self.num_nodes = len(self.D)
        self.cnt = 0

        self.G = [[int(n) for n in line.strip().split()[1:]] for line in open(graph_path, 'r', encoding='UTF8')]
        #print("loading graph complete.")

        self.querys = [ tuple(float(item) for item in line.strip().split()) for line in open(query_path, 'r', encoding='UTF8')]
        #print("loading query complete.")

        self.visited = [0] * self.num_nodes
        self.vmark = 2
        self.omark = 1

    def reset_visited(self):
        if self.vmark == MAXINT:
            self.vmark = 2
            self.omark = 1
            for i in range(len(self.visited)):
                self.visited[i] = 0
        else:
            self.vmark += 2
            self.omark += 2

    def parse_line(self, line):
        items = line.strip().split()
        word = items[0]
        vector = tuple(float(item) for item in items[1:])
        return (word, vector)

    # p: start point
    # q: query point
    # l: heap size
    # k: return points
    def k_greedy_search(self, p, q, l, k, metric):

        self.reset_visited()

        dist_pq = dist(self.D[p], self.querys[q], metric)
        S = [Candidate(dist_pq, p)]

        while True:
            i, pi = next(((i, s) for i, s in enumerate(S) if self.visited[s.id] != self.vmark), (None, None))

            if i == None: break

            self.visited[pi.id] = self.vmark
            for n in self.G[pi.id]:
                if self.visited[n] < self.omark:
                    self.cnt += 1
                    self.visited[n] = self.omark
                    S.append(Candidate(dist(self.D[n], self.querys[q], metric), n))

            S.sort()
            while len(S) > l:
                S.pop()

        return S[:k]

    def greedy_search(self, p, q):
        min_dist = dist(self.D[p], self.querys[q], metric)

        while True:
            if len(self.D[p]) == 0:
                break

            cdist, c = min((dist(self.D[n], self.querys[q], metric), n) for n in self.G[p])

            if cdist < min_dist:
                self.cnt += 1
                min_dist = cdist
                p = c
            else:
                break

        return p


data_path = sys.argv[1]
graph_path = sys.argv[2]
query_path = sys.argv[3]
anns = ANNS(data_path, graph_path, query_path)

answer_path = sys.argv[4]

metric = 'c'
k = 10
heap_size = [20, 40, 60, 80, 100]

answers = [set(int(n) for n in line.strip().split()[:k]) for line in open(answer_path, 'r', encoding='UTF8')]


for l in heap_size:

    results = []

    t1 = time.time()
    for q in tqdm(range(len(anns.querys))):

        p = random.randint(0, anns.num_nodes - 1)
        res = anns.k_greedy_search(p, q, l, k, metric)
        results.append(res)

    t2 = time.time()
    sec = int(t2 - t1)
    query_per_sec = len(anns.querys) / sec

    recall_sum = 0

    for q, res in tqdm(enumerate(results)):

        ans = answers[q]
        true_positive = 0
        for n in res:
            id = n.id
            if id in ans: true_positive +=1

        recall = true_positive / k
        recall_sum += recall

    recall_mean = recall_sum / len(anns.querys)

    print("query per second: {}\nrecall: {}".format(int(query_per_sec), round(recall_mean, 3)))
    print("move: {}".format(anns.cnt))
    anns.cnt = 0
    sys.stdout.flush()
