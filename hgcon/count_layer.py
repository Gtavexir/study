### 각 계층에 몇 개으의 엣지가 존재하는지 세는 파일

import sys

graph_path = sys.argv[1]
max_layer = int(sys.argv[2]) #레이어 층

layer_cnt = [0 for _ in range(max_layer)]

f = open(graph_path, 'r')
for line in f:
    items = line.strip().split()
    v = int(items[0])
    arr = items[1:]
    for i in range(0, len(arr), 2):
        layer_cnt[int(arr[i+1])] += 1

for i in range(len(layer_cnt)):
    print(i, ":", layer_cnt[i])

print(sum(layer_cnt))
