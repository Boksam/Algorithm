from collections import deque
import sys

ladders = []
snakes = []
visited = [-1 for _ in range(101)]

def BFS():
    q = deque()
    q.append(1)
    visited[1] = 0

    time = 0

    while q:
        tempQ = deque()

        while q:
            currX = q.popleft()
            
            for dx in range(1, 7):
                newX = currX + dx
                for ladder in ladders:
                    if ladder[0] == newX:
                        newX = ladder[1]
                        break
                for snake in snakes:
                    if snake[0] == newX:
                        newX = snake[1]
                        break

                if newX > 100:
                    continue
                
                if visited[newX] == -1 or visited[newX] > time + 1:
                    visited[newX] = time + 1
                    tempQ.append(newX)
        time += 1
        q = tempQ
        
    return visited[100]





if __name__ == '__main__':
    N, M = map(int, sys.stdin.readline().split(' '))
    for _ in range(N):
        start, end = map(int, sys.stdin.readline().split(' '))
        ladders.append((start, end))
    for _ in range(M):
        start, end = map(int, sys.stdin.readline().split(' '))
        snakes.append((start, end))
    
    print(BFS())