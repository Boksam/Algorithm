# abadf
INF = 1e9

def CheckPalin(is_palin):
    for i in range(n):
        is_palin[i][i] = True
    for i in range(n-1):
        if s[i] == s[i+1]:
            is_palin[i][i+1] = True
    for l in range(2, n):
        for i in range(n-l):
            e = i + l
            if s[i] == s[e] and is_palin[i+1][e-1]:
                is_palin[i][e] = True


def Solve(dp):
    for end in range(n):
        for start in range(end+1):
            if is_palin[start][end]:
                dp[end] = min(dp[end], dp[start-1] + 1)

s = input()
n = len(s)
dp = [INF for _ in range(n+1)]
dp[-1] = 0
is_palin = [[False for _ in range(n)] for _ in range(n)]

CheckPalin(is_palin)
Solve(dp)

print(dp[n-1])