num_list = []
bool_num_list = []


def solve(n):
    global num_list, bool_num_list
    
    if n == M:
        for num in num_list:
            print(num, end=" ")
        print()
        return
    
    for num in range(1, N + 1):
        if bool_num_list[num] == False:
            num_list.append(num)
            bool_num_list[num] = True

            solve(n + 1)

            num_list.pop()
            bool_num_list[num] = False


if __name__ == "__main__":
    N, M = map(int, input().split())
    bool_num_list = [False] * (N + 1)
    solve(0)