import sys

def bellman_ford(start):
    INF = int(1e9)
    dist = [INF for i in range(N+1)]
    dist[start] = 0
    for i in range(N):
        for s, e, t in roads:
            if dist[e] > dist[s] + t:
                if i == N - 1:
                    return True
                dist[e] = dist[s] + t
    return False

TC = int(sys.stdin.readline())
for _ in range(TC):
    N, M, W = map(int, sys.stdin.readline().split(' '))

    roads = []

    for i in range(M):
        S, E, T = map(int, sys.stdin.readline().split(' '))
        roads.append([S, E, T])
        roads.append([E, S, T])
    for i in range(W):
        S, E, T = map(int, sys.stdin.readline().split(' '))
        roads.append([S, E, -T])

    if bellman_ford(1):
        print('YES')
    else:
        print('NO')

