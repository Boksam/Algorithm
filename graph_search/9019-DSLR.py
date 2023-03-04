from collections import deque

def BFS(A, B):  # A, B는 int
    # queue에는 int로 된 값, 현재까지 사용된 명령어 tuple 저장
    queue = deque()
    queue.append((A, ''))
    visit = [False] * 10000
    
    while len(queue) != 0:
        currNum, currCmd = queue.popleft()
        visit[currNum] = True
        if currNum == B:
            return currCmd
        
        
        
        newNum = (currNum * 2) % 10000
        if not visit[newNum]:
            queue.append((newNum, currCmd + 'D'))
            visit[newNum] = True

        newNum = (currNum - 1) % 10000
        if not visit[newNum]:
            queue.append((newNum, currCmd + 'S'))
            visit[newNum] = True

        newNum = (10 * currNum + (currNum // 1000)) % 10000
        if not visit[newNum]:
            queue.append((newNum, currCmd + 'L'))
            visit[newNum] = True

        newNum = (currNum // 10 + (currNum % 10) * 1000) % 10000
        if not visit[newNum]:
            queue.append((newNum, currCmd + 'R'))
            visit[newNum] = True
            

if __name__ == '__main__':
    T = int(input())

    for _ in range(T):
        A, B = map(int, input().split(' '))
        print(BFS(A, B))
