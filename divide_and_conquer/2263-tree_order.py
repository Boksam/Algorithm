import sys
sys.setrecursionlimit(10**5)

def solve(p_start, p_end, i_start, i_end):
    root = post_order[p_end]
    sys.stdout.write(str(root) + ' ')

    root_idx_in_order = in_order.index(root)
    right_post_order = p_start + (root_idx_in_order - i_start)
    
    
    if p_start <= right_post_order - 1 and  i_start <= root_idx_in_order - 1:
        solve(p_start, right_post_order - 1, i_start, root_idx_in_order - 1)
    if right_post_order <= p_end - 1 and root_idx_in_order + 1 <= i_end:
        solve(right_post_order, p_end - 1, root_idx_in_order + 1, i_end)
    



N = int(sys.stdin.readline())

in_order = list(map(int, sys.stdin.readline().split()))
post_order = list(map(int, sys.stdin.readline().split()))

solve(0, len(post_order) - 1, 0, len(in_order) - 1)
sys.stdout.write('\n')