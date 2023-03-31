import sys

board = []

N = int(sys.stdin.readline())

max_sum = [0 for i in range(3)]
min_sum = [0 for i in range(3)]

max_sum = list(map(int, sys.stdin.readline().split(' ')))
min_sum = max_sum[:]


for _ in range(1, N):
    a, b, c = map(int, sys.stdin.readline().split())
    
    max_sum = [a + max(max_sum[0], max_sum[1]), b + max(max_sum), c + max(max_sum[1], max_sum[2])]
    min_sum = [a + min(min_sum[0], min_sum[1]), b + min(min_sum), c + min(min_sum[1], min_sum[2])]

print(max(max_sum), min(min_sum))