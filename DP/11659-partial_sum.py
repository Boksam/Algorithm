import sys

N, M = map(int, sys.stdin.readline().split(' '))
nums = list(map(int, sys.stdin.readline().split(' ')))
sums = [0, nums[0]]
for i in range(1, N):
    sums.append(sums[i] + nums[i])

for _ in range(M):
    start, end = map(int, sys.stdin.readline().split(' '))
    
    sys.stdout.write(str(sums[end] - sums[start-1]) + '\n')