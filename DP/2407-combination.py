n, m = map(int, input().split())

dp = [[0 for i in range(m+1)] for j in range(n+1)]

for i in range(n+1):
    for j in range(m+1):
        if i < j:
            break
        if j == 0 or i == j:
            dp[i][j] = 1
        else:
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j]
print(dp[n][m])