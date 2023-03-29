import sys

n = int(sys.stdin.readline())

def DFS(start):
    visited = [False for i in range(n+1)]
    distances = [-1 for i in range(n+1)]

    stack = []
    stack.append(start)
    distances[start] = 0
    visited[start] = True

    maxV = start
    maxD = 0

    while stack:
        currentV = stack.pop()
        visited[currentV] = True
        for nextV, nextW in edges[currentV]:
            nextD = nextW + distances[currentV]
            if not visited[nextV]:
                distances[nextV] = nextD
                stack.append(nextV)
                if nextD > maxD:
                    maxV = nextV
                    maxD = nextD
    return [maxV, maxD]



edges = [[] for i in range(n+1)]

for _ in range(n-1):
    start, end, weight = map(int, sys.stdin.readline().split())
    edges[start].append([end, weight])
    edges[end].append([start, weight])

firstV, firstD = DFS(1)
secondV, secondD = DFS(firstV)

print(secondD)