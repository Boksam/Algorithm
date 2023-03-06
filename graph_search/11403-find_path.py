nodes = []

def DFS(N):
    for i in range(N):
        visited = [False for _ in range(N)]
        answer = []
        q = nodes[i][:]
        while q:
            curr_node = q.pop()
            if not visited[curr_node]:
                visited[curr_node] = True
                answer.append(curr_node)
                q += nodes[curr_node]
        for j in range(N):
            if j in answer:
                print(1, end=' ')
            else:
                print(0, end=' ')
        print()
    

if __name__ == "__main__":
    N = int(input())
    for i in range(N):
        adjacent_node = []
        total_node_list = list(map(int, input().split(' ')))
        for j in range(N):
            if total_node_list[j] == 1:
                adjacent_node.append(j)
        nodes.append(adjacent_node)
    DFS(N)