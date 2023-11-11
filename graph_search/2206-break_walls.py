import sys
from collections import deque

dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]

def BFS():
    q = deque()
    visited = [[[0] * 2 for i in range(M)] for j in range(N)]
    visited[0][0][0] = 1
    q.append([0, 0, 0])

    while q:
        currY, currX, broke = q.popleft()

        if currY == N-1 and currX == M-1:
            return visited[currY][currX][broke]
        
        for i in range(4):
            newY = currY + dy[i]
            newX = currX + dx[i]

            if not (0 <= newY < N) or not (0 <= newX < M):
                continue

            if m[newY][newX] == '1' and broke == 0:
                visited[newY][newX][1] = visited[currY][currX][0] + 1
                q.append([newY, newX, 1])
            elif m[newY][newX] == '0' and visited[newY][newX][broke] == 0:
                visited[newY][newX][broke] = visited[currY][currX][broke] + 1
                q.append([newY, newX, broke])
    return -1




N, M = map(int, sys.stdin.readline().split())
m = []
for i in range(N):
    m.append(sys.stdin.readline())

print(BFS())