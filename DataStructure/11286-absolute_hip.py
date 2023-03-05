import heapq
import sys

q = []
N = int(sys.stdin.readline())
for _ in range(N):
    n = int(sys.stdin.readline())
    if n == 0:
        if q:
            print(heapq.heappop(q)[1])
        else:
            print(0)
    else:
        heapq.heappush(q, (abs(n), n))