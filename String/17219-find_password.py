import sys

memo = dict()

N, M = map(int, sys.stdin.readline().split(' '))

for _ in range(N):
    domain, password = sys.stdin.readline().rstrip().split(' ')
    memo[domain] = password

for _ in range(M):
    domain = sys.stdin.readline().rstrip()
    sys.stdout.write(memo[domain] + '\n')