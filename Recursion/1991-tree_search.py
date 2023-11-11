import sys

def preorder_traversal(root):
    print(root, end='')

    if nodes[root][0] != '.':
        preorder_traversal(nodes[root][0])

    if nodes[root][1] != '.':
        preorder_traversal(nodes[root][1])

def inorder_traversal(root):
    if nodes[root][0] != '.':
        inorder_traversal(nodes[root][0])

    print(root, end='')
    
    if nodes[root][1] != '.':
        inorder_traversal(nodes[root][1])

def postorder_traversal(root):
    if nodes[root][0] != '.':
        postorder_traversal(nodes[root][0])

    if nodes[root][1] != '.':
        postorder_traversal(nodes[root][1])

    print(root, end='')


N = int(sys.stdin.readline())
nodes = {}      # left, right

for _ in range(N):
    root, left, right = sys.stdin.readline().split()
    nodes[root] = [left, right]

preorder_traversal('A')
print()
inorder_traversal('A')
print()
postorder_traversal('A')
print()