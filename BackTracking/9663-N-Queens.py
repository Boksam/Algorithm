from sys import stdin, stdout

N = int(stdin.readline())

board = [0 for _ in range(N)]

result = 0


def solve(n):
    global result
    
    if n == N:
        result += 1
        return

    for i in range(N):
        board[n] = i

        if check(n):
            solve(n + 1)

            
def check(n):
    for i in range(n):
        if board[n] == board[i] or abs(board[n] - board[i]) == abs(n - i):
            return False
    return True


solve(0)
stdout.write(str(result) + '\n')