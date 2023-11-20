import sys

left = list(sys.stdin.readline().rstrip())
right = []

for _ in range(int(sys.stdin.readline())):
    line = list(sys.stdin.readline())

    if line[0] == 'L':
        if left:
            right.append(left.pop())
    elif line[0] == 'D':
        if right:
            left.append(right.pop())
    elif line[0] == 'B':
        if left:
            left.pop()
    else:
        left.append(line[2])

answer = ''.join(c for c in left) + ''.join(c for c in reversed(right))
print(answer)
