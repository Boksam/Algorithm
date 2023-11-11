N, S = map(int, input().split())

nums = list(map(int, input().split()))
ans = 0

def back_tracking(i, curr_sum):
    global ans

    if i >= N:
        return
    
    curr_sum += nums[i]

    if curr_sum == S:
        ans += 1

    back_tracking(i + 1, curr_sum)
    back_tracking(i + 1, curr_sum - nums[i])

back_tracking(0, 0)
print(ans)