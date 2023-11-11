import sys
sys.setrecursionlimit(100000)


l = []

def recursion(s, e):
    if s == e:
        print(l[s])
        return
    
    if s > e:
        return
    
    root = l[s]
    right = s + 1
    while right < len(l):
        if l[right] > root:
            break
        right += 1
    
    recursion(s + 1, right - 1)
    recursion(right, e)
    recursion(s, s)
    


if __name__ == '__main__':
    
    while True:
        try:
            n = int(input())
            l.append(n)
        except:
            break

    recursion(0, len(l) - 1)