n = int(input())

dp = [1, 3]
for i in range(2, 1001):
    dp.append((dp[i-2] * 2 + dp[i-1]) % 10007)

print(dp[n-1])