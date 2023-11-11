from collections import deque

N = 0
sea = []

# 상 -> 좌 -> 우 -> 하 순으로 이동
dy = [-1, 0, 0, 1]
dx = [0, -1, 1, 0]

def BFS(N, init_shark_pos):
    shark_pos = init_shark_pos[:]
    shark_size = 2
    shark_exp = 0
    time = 0

    while True:
        valid, nextPos, spent_time = search_move(shark_pos[0], shark_pos[1], shark_size)
        if valid:
            shark_exp += 1
            if shark_size == shark_exp:
                shark_size += 1
                shark_exp = 0
            shark_pos = nextPos[:]
            time += spent_time
        else:
            return time

    
    
    
def search_move(currY, currX, shark_size):      # [먹었는지, 새위치, 소요시간] 반환
    global sea

    visited = [[False for j in range(N)] for i in range(N)]
    q = deque()
    q.append([currY, currX])
    
    time = 0
    while q:
        tempQ = deque()
        answer = [100, 100]
        found = False
        
        while q:
            currY, currX = q.popleft()
            if sea[currY][currX] != 0 and sea[currY][currX] < shark_size:
                found = True
                if doChange(answer[0], answer[1], currY, currX):
                    answer = [currY, currX]
            
            if not found:
                for i in range(4):
                    nextY = currY + dy[i]
                    nextX = currX + dx[i]
                    if isValid(nextY, nextX) and not visited[nextY][nextX]:
                        if sea[nextY][nextX] <= shark_size:
                                tempQ.append([nextY, nextX])
                                visited[nextY][nextX] = True
        if not found:
            time += 1
            q = tempQ

    if found:
        sea[answer[0]][answer[1]] = 0
        return [True, answer, time]
    else:
        return [False, [currY, currX], time]


def isValid(y, x):
    return 0 <= y < N and 0 <= x < N

def doChange(currY, currX, newY, newX):
    if newY < currY:
        return True
    if newY == currY and newX < currX:
        return True
    return False


if __name__ == '__main__':
    N = int(input())
    init_shark_pos = []
    for y in range(N):
        line = list(map(int, input().split(' ')))
        for x in range(N):
            if line[x] == 9:
                init_shark_pos = [y, x]
                line[x] = 0
                break
        sea.append(line)
    
    print(BFS(N, init_shark_pos))