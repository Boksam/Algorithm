
def isAllZero(y, x, size):
    for i in range(y, y + size):
        for j in range(x, x + size):
            if floor[i][j] != 0:
                return False
    return True


def divide_and_conquer(y, x, size):
    global idx, floor

    half_size = size // 2
    if isAllZero(y, x, half_size):
        floor[y + half_size - 1][x + half_size - 1] = idx
    if isAllZero(y, x + half_size, half_size):
        floor[y + half_size - 1][x + half_size] = idx
    if isAllZero(y + half_size, x, half_size):
        floor[y + half_size][x + half_size - 1] = idx
    if isAllZero(y + half_size, x + half_size, half_size):
        floor[y + half_size][x + half_size] = idx

    idx += 1

    if size == 2:
        return

    

    divide_and_conquer(y, x, half_size)
    divide_and_conquer(y, x + half_size, half_size)
    divide_and_conquer(y + half_size, x, half_size)
    divide_and_conquer(y + half_size, x + half_size, half_size)




n = int(input())
full_size = 2 ** n
p1, p2 = map(int, input().split())
idx = 1

floor = [[0 for i in range(2 ** n)] for j in range(2 ** n)]

floor[full_size - p2][p1 - 1] = -1

divide_and_conquer(0, 0, full_size)

for y in range(full_size):
    for x in range(full_size):
        print(floor[y][x], end=' ')
    print()
