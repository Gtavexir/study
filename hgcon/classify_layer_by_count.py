# 레이어 나누는 기준을 이용해 계층으로 그래프 바꾸는 파일

import sys
from tqdm import tqdm

def cosine_distance(vec_a, vec_b):
    ab = (sum(a ** 2 for a in vec_a) * sum(b ** 2 for b in vec_b)) ** 0.5
    if ab == 0:
        return 0
    a_dot_b = sum(a * b for a, b in zip(vec_a, vec_b))
    return 1 - (a_dot_b / ab)

def parse_vector(line):
    items = line.strip().split()
    word = items[0]
    vector = tuple(float(item) for item in items[1:])
    return vector

def parse_graph(line):
    items = line.strip().split()
    word = items[0]
    vector = tuple(int(item) for item in items[1:])
    return vector

vector_path = "../data/glove_25_angular/train.txt" # sys.argv[1]
graph_path = sys.argv[1]

vector = [parse_vector(line) for line in open(vector_path, 'r', encoding='UTF8')]
graph = [parse_graph(line) for line in open(graph_path, 'r', encoding='UTF8')]

layer_set = [112967, 98861, 86813, 75086, 62551, 48431, 32890, 18897]

h_graph = [[] for _ in range(len(vector))]

for i in tqdm(range(len(vector))):
    a = vector[i]  # 기준 노드 벡터
    for j in range(len(graph[i])):
        b = vector[graph[i][j]] # 이웃 노드 벡터
        dist = int(cosine_distance(a, b) * 1e5)  # 기준 노드와 이웃 노드 간의 거리
        h_graph[i].append(graph[i][j])
        for k in range(len(layer_set)):
            if dist >= layer_set[k]:
                h_graph[i].append(k)
                break
        else:
            h_graph[i].append(len(layer_set))

for i in tqdm(range(len(h_graph))):
    print(i, end=' ')
    for j in range(len(h_graph[i])):
        print(h_graph[i][j], end=' ')
    print('')
