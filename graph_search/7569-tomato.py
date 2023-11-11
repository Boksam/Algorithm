M, N, H = 0, 0, 0
box = []

dz = [1, -1, 0, 0, 0, 0]
dy = [0, 0, -1, 1, 0, 0]
dx = [0, 0, 0, 0, -1, 1]


def BFS():
    queue = []
    unRiped, time = 0, 0

    # 익은 토마토 큐에 모두 저장
    for z in range(H):
        for y in range(N):
            for x in range(M):
                if box[z][y][x] == 1:
                    queue.append((z, y, x))
                elif box[z][y][x] == 0:
                    unRiped += 1

    # 익은 게 하나도 없으면 0 리턴
    if unRiped == 0:
        return 0
    
    # 큐를 전부 비워가며 모든 토마토가 익을때까지 탐색
    while len(queue) != 0:
        newQueue = []
        while len(queue) != 0:
            currZ, currY, currX = queue.pop()
            for i in range(6):
                newZ, newY, newX = (currZ + dz[i], currY + dy[i], currX + dx[i])
                if isValid(newZ, newY, newX):
                    newQueue.append((newZ, newY, newX))
                    box[newZ][newY][newX] = 1
                    unRiped -= 1
        if len(newQueue) == 0:
            break
        else:
            time += 1
            queue = newQueue
    
    if unRiped == 0:
        return time
    else:
        return -1


def isValid(z, y, x):
    return 0 <= z < H and 0 <= y < N and 0 <= x < M and box[z][y][x] == 0



if __name__ == "__main__":
    M, N, H = map(int, input().split(' '))
    for i in range(H):
        square = []
        for j in range(N):
            line = list(map(int, input().split(' ')))
            square.append(line)
        box.append(square)
    
    print(BFS())