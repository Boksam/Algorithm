N = int(input())
M = int(input())
S = input()

count = 0

cursor = 0
IOIcount = 0
while cursor < M:
    if S[cursor : cursor + 3] == 'IOI':
        IOIcount += 1
        if IOIcount == N:
            count += 1
            IOIcount -= 1
        cursor += 2
    else:
        IOIcount = 0
        cursor += 1

print(count)