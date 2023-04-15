N, K = map(int, input().split())

elems = [list(map(int, input().split())) for _ in range(N)]
elems.sort()
dp = [[0 for _ in range(K+1)] for _ in range(N+1)]

for i in range(N + 1):
    for w in range(K + 1):
        if i == 0 or w == 0:
            dp[i][w] = 0
        elif elems[i-1][0] <= w:
            dp[i][w] = max(dp[i-1][w - elems[i-1][0]] + elems[i-1][1], dp[i-1][w])
        else:
            dp[i][w] = dp[i-1][w]


print(dp[N][K])