import sys

vertex = []

def DFS(init):
    dist = [-1 for i in range(N+1)]
    visited = [False for i in range(N+1)]
    s = []

    s.append(init)
    dist[init] = 0
    visited[init] = True
    maxV = init
    maxD = 0
    while s:
        curr = s.pop()
        visited[curr] = True
        for newV_D in vertex[curr]:     # newV_D 에는 [인접 index, 거리값]
            newV = newV_D[0]
            newD = dist[curr] + newV_D[1]
            if not visited[newV]:
                dist[newV] = newD
                s.append(newV)
                if newD > maxD:
                    maxV = newV
                    maxD = newD
    
    return [maxV, maxD]


if __name__ == "__main__":
    N = int(sys.stdin.readline())

    vertex = [[] for i in range(N+1)] # [vertex 숫자][인접 vertex][distance]

    for _ in range(N):
        line = list(map(int, sys.stdin.readline().split(' ')))
        v = line[0]
        init = v
        i = 1
        while i < len(line) - 1:
            newL = [line[i], line[i+1]]
            vertex[v].append(newL)
            i += 2

    firstV, firstD = DFS(init)
    secondV, secondD = DFS(firstV)

    print(secondD)