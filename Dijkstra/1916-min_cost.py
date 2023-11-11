import sys, heapq

def dijkstra(start, end):
    INF = float('inf')
    q = []
    costs = [INF for i in range(N + 1)]
    costs[start] = 0
    heapq.heappush(q, [costs[start], start])

    while q:
        curr_cost, curr_destination = heapq.heappop(q)

        if curr_cost > costs[curr_destination]:
            continue

        for next_destination, next_cost in bus[curr_destination]:
            distance = curr_cost + next_cost
            if distance < costs[next_destination]:
                costs[next_destination] = distance
                heapq.heappush(q, [distance, next_destination])
    
    return costs[end]


N = int(sys.stdin.readline())
M = int(sys.stdin.readline())

bus = [[] for i in range(N+1)]

for _ in range(M):
    s, e, c = map(int, sys.stdin.readline().split())
    bus[s].append([e,c])

start, end = map(int, sys.stdin.readline().split())

print(dijkstra(start, end))