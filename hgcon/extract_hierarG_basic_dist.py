# 계층을 거리로만 나눌 때 기준이 몇인지 구하는 파일

import sys
from tqdm import tqdm

k_point = 100000  # 소수점 자리 몇번째까지 표현할 것인가..!

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

vector_path = sys.argv[1]
graph_path = sys.argv[2]

vector = [parse_vector(line) for line in open(vector_path, 'r', encoding='UTF8')]
graph = [parse_graph(line) for line in open(graph_path, 'r', encoding='UTF8')]

maxi = -1
for i in tqdm(range(len(graph))):
    a = vector[i]  # 기준 노드
    for j in range(len(graph[i])):
        b = vector[graph[i][j]] # 이웃 노드 벡터
        dist = int(cosine_distance(a, b) * k_point)  # 기준 노드와 이웃 노드 간의 거리
        maxi = max(dist, maxi)

cut_len = []
layer_cnt = 9
k = maxi // (layer_cnt + 1)
for i in range(layer_cnt - 1):
	cut_len.append(maxi - k)
	maxi -= k
	
print(cut_len)
