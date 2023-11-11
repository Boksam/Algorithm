import sys, heapq

def dijkstra(K):
    distances = [float('inf') for i in range(V+1)]
    distances[K] = 0
    q = []
    heapq.heappush(q, [distances[K], K])

    while q:
        curr_distance, curr_destination = heapq.heappop(q)
        if curr_distance > distances[curr_destination]:
            continue

        for new_destination, new_distance in graph[curr_destination]:
            distance = curr_distance + new_distance
            if distance < distances[new_destination]:
                distances[new_destination] = distance
                heapq.heappush(q, [distance, new_destination])
    for cost in distances[1:]:
        if cost == float('inf'):
            sys.stdout.writelines('INF\n')
        else:
            sys.stdout.writelines(str(cost)+'\n')

V, E = map(int, sys.stdin.readline().split(' '))
K = int(sys.stdin.readline())

graph = [[] for i in range(V+1)]    #[시작노드번호][도착노드번호][거리]

for _ in range(E):
    start, end, cost = map(int, sys.stdin.readline().split(' '))
    graph[start].append([end, cost])

dijkstra(K)