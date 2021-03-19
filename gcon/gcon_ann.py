import sys
import random
from tqdm import tqdm
import argparse
from collections import namedtuple

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
    a_dot_b = sum(a * b for a, b in zip(vec_a, vec_b))
    return 1 - (a_dot_b / ab)


# q: query vector
# s: start point
# adj: graph in adjacency list format


class GConAnn:

    def __init__(self, data, initial_adj=None, metric='c', heap_size=10, k=1):
        self.vectors = [v for w, v in data]
        self.metric = metric

        if initial_adj == None:
            self.adj = [[] for _ in self.vectors]
            self.num_edges = 0
            self.prefix = ""
        else:
            self.adj = initial_adj
            self.prefix = "init"
            self.num_edges = sum(len(x) for x in initial_adj)

        self.mindists = [float("inf")] * len(self.vectors)

        # ANNS parameter
        self.visited = [0] * len(self.vectors)
        self.vmark = 2
        self.omark = 1
        self.heap_size = heap_size
        self.k = k

        self.construct()

    def construct(self):

        for it in range(10000):
            num_succ = 0
            for q, qvec in enumerate(tqdm(self.vectors, desc=f"grd-{self.heap_size}-{it}-build")):

                a = self.k_ann_search(qvec, random.randint(0, len(self.vectors) - 1), self.heap_size, self.k, self.metric)

                if a != q:
                    self.adj[a].append([q, 1, it])
                    self.num_edges += 1

                    dist_aq = self.distance(self.vectors[a], self.vectors[q])

                    if dist_aq < self.mindists[a]:
                        self.mindists[a] = dist_aq
                else:
                    num_succ += 1
            print(f"{it}-1:\t{self.num_edges}\t{num_succ}")

            if it % 10 == 0:
                self.save_adj_as_file(
                    f"./adj_iter_{self.heap_size}_{self.k}_{self.prefix}_{it}")

            num_succ_real = 0
            for q, qvec in enumerate(tqdm(self.vectors, desc=f"grd-{self.heap_size}-{it}-test")):
                a = self.k_ann_search(qvec, random.randint(0, len(self.vectors) - 1), self.heap_size, self.k, self.metric)
                if a == q:
                    num_succ_real += 1

            print(f"{it}-2:\t{self.num_edges}\t{num_succ_real}")
            sys.stdout.flush()

    def reset_visited(self):
        if self.vmark == MAXINT:
            self.vmark = 2
            self.omark = 1
            for i in range(len(self.visited)):
                self.visited[i] = 0
        else:
            self.vmark += 2
            self.omark += 2

    def k_ann_search(self, q, s, l, k, metric):
        self.reset_visited()

        dist_pq = self.distance(self.vectors[s], q)
        S = [Candidate(dist_pq, s)]

        while True:
            i, pi = next(((i, s) for i, s in enumerate(S) if self.visited[s.id] != self.vmark), (None, None))

            if i == None: break

            self.visited[pi.id] = self.vmark
            for n, _, __ in self.adj[pi.id]:
                if self.visited[n] < self.omark:
                    self.visited[n] = self.omark
                    S.append(Candidate(self.distance(self.vectors[n], q), n))

            S.sort()
            while len(S) > l:
                S.pop()

        return S[0].id # k = 1일 때 설정 (수정 필요)

    def distance(self, vec_a, vec_b):
        if self.metric == 'e':
            return euclidean_distance(vec_a, vec_b)
        elif self.metric == 'c':
            return cosine_distance(vec_a, vec_b)

    def save_adj_as_file(self, path):
        with open(path, 'w') as f:
            for i, arr in enumerate(self.adj):
                f.write(f"{i}")
                for a, _, __ in arr:
                    f.write(f" {a}")
                f.write("\n")

def parse_line(line):
    items = line.strip().split()
    word = items[0]
    vector = tuple(float(item) for item in items[1:])
    return (word, vector)


def parse_graph(gpath, num_nodes):
    initial_graph = [[] for _ in range(num_nodes)]

    for line in open(gpath, 'r'):
        items = (int(w) for w in line.strip().split())
        u = next(items)
        initial_graph[u] = [[v, 1] for v in items]

    return initial_graph


parser = argparse.ArgumentParser(prog='gcon_greedy')
parser.add_argument('-i', metavar='INITIAL_GRAPH', help='initial graph')
parser.add_argument('-m', metavar='DISTANCE_METRIC', help='distance_metric')
parser.add_argument('-heap', metavar='HEAP_SIZE', type=int, default=10)
parser.add_argument('-k', metavar='RETURN_POINTS', type=int, default=1)

args = parser.parse_args(sys.argv[1:])

sys.stderr.write(f"{args}\n")

data = [parse_line(line) for line in sys.stdin]

initial_graph = parse_graph(args.i, len(data)) if args.i else None
gcg = GConAnn(data, initial_graph, metric=args.m, heap_size=args.heap, k=args.k)