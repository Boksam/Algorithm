
pic = []
N = 0
dx = [0, 0, -1, 1]
dy = [1, -1, 0, 0]

def DFS(haveWeakness):

    q = []
    count = 0
    visited = [[False for j in range(N)] for i in range(N)]
    for i in range(N):
        for j in range(N):
            if not visited[i][j]:
                color = pic[i][j]
                q.append((i, j))
                while q:
                    currY, currX = q.pop()
                    visited[currY][currX] = True
                    for k in range(4):
                        newY, newX = (currY + dy[k], currX + dx[k])
                        if isValid(newY, newX, color, haveWeakness, visited):
                            q.append((newY, newX))
                count += 1
    return count


def isValid(y, x, color, haveWeakness, visited):
    if (y < 0) or (y >= N) or (x < 0) or (x >= N):
        return False
    if visited[y][x]:
        return False
    
    flag = (color == pic[y][x])
    if haveWeakness and ((color == 'R' and pic[y][x] == 'G') or (color == 'G' and pic[y][x] == 'R')):
        flag = True
    return flag



if __name__ == "__main__":
    N = int(input())
    for _ in range(N):
        line = input()
        pic.append(line)
    
    print(DFS(False), DFS(True))
