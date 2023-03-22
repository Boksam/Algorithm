import sys, heapq

total = []

def dijkstra(start, end):
    queue = []
    distances = [float('inf') for i in range(N+1)]
    distances[start] = 0
    heapq.heappush(queue, [distances[start], start])

    while queue:
        curr_distance, curr_destination = heapq.heappop(queue)

        if distances[curr_destination] < curr_distance:
            continue

        for new_destination, new_distance in roads[curr_destination]:
            distance = curr_distance + new_distance
            if distance < distances[new_destination]:
                distances[new_destination] = distance
                heapq.heappush(queue, [distance, new_destination])
    
    return distances[end]
    



N, M, X = map(int, sys.stdin.readline().split(' '))

total = [0 for i in range(N+1)]
roads = [[] for i in range(N+1)]    # [마을숫자][도착마을숫자][소요시간]

for _ in range(M):
    start, end, time = map(int, sys.stdin.readline().split(' '))  # 거꾸로 탐색할거니까 거꾸로 저장
    roads[start].append([end, time])

max_distance = 0
for i in range(1, N+1):
    total[i] += dijkstra(i, X) + dijkstra(X, i)
    max_distance = max(max_distance, total[i])

print(max_distance)