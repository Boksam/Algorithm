import sys

str1 = input()
str2 = input()

str1 = '0' + str1
str2 = '0' + str2

str1_size = len(str1)
str2_size = len(str2)

dp = [[0 for _ in range(str1_size)] for _ in range(str2_size)]

for i in range(1, str2_size):
    for j in range(1, str1_size):
        if i == 0 or j == 0:
            dp[i][j] = 0
        elif str2[i] == str1[j]:
            dp[i][j] = dp[i-1][j-1] + 1
        else:
            dp[i][j] = max(dp[i-1][j], dp[i][j-1])

print(dp[str2_size - 1][str1_size - 1])