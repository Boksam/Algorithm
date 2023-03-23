import sys
import heapq

graph = []

def dijkstra(start, end):
    distances = [float('inf') for i in range(N+1)]
    distances[start] = 0
    s = []
    heapq.heappush(s, [distances[start], start])

    while s:
        curr_distance, curr_destination = heapq.heappop(s)
        
        if curr_distance > distances[curr_destination]:
            continue

        for next_destination, next_distance in graph[curr_destination]:
            distance = distances[curr_destination] + next_distance
            if distance < distances[next_destination]:
                distances[next_destination] = distance
                heapq.heappush(s, [distance, next_destination])
                
    return distances[end]


N, E = map(int, sys.stdin.readline().split(' '))
graph = [[] for i in range(N+1)]
for _ in range(E):
    p1, p2, cost = map(int, sys.stdin.readline().split(' '))
    graph[p1].append([p2, cost])
    graph[p2].append([p1, cost])
v1, v2 = map(int, sys.stdin.readline().split(' '))

dist1 = dijkstra(1, v1) + dijkstra(v1, v2) + dijkstra(v2, N)
dist2 = dijkstra(1, v2) + dijkstra(v2, v1) + dijkstra(v1, N)

answer = min(dist1, dist2)
if answer == float('inf'):
    print(-1)
else:
    print(answer)