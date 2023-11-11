N = 0
map = []
visited = []
answers = []

diffX = [0, 0, -1, 1]
diffY = [-1, 1, 0, 0]


def input_village():
    global N, map, visited

    N = int(input())
    for _ in range(N):
        line = input()
        map.append(line)
    visited = [[False for j in range(N)] for i in range(N)]


def isValid(y, x):
    return 0 <= y < N and 0 <= x < N


def DFS():
    global N, map, visited, answers, diffX, diffY

    for i in range(N):
        for j in range(N):
            if not visited[i][j] and map[i][j] == '1':
                count = 0
                stack = [[i, j]]
                visited[i][j] = True
                
                while len(stack) != 0:
                    count += 1
                    current = stack.pop()

                    for k in range(4):
                        currY, currX = current[0] + diffY[k], current[1] + diffX[k]
                        if isValid(currY, currX) and not visited[currY][currX] and map[currY][currX] == '1':
                            stack.append([currY, currX])
                            visited[currY][currX] = True
                answers.append(count)


if __name__ == "__main__":
    input_village()
    DFS()

    print(len(answers))
    for ans in sorted(answers):
        print(ans)