def printList(numList, front):
    print('[', end='')
    if front:
        for i in range(len(numList)):
            if i == 0:
                print(numList[i], end='')
            else:
                print(',', numList[i], sep='',end='')
    else:
        for i in range(len(numList) - 1, -1, -1):
            if i == len(numList) - 1:
                print(numList[i], end='')
            else:
                print(',', numList[i], sep='', end='')
    print(']')



T = int(input())

for _ in range(T):
    numList = []
    front = True
    commands = input()
    n = int(input())
    
    if n == 0:
        input()
    else:
        numList = list(map(int, input().replace('[', '').replace(']', '').split(',')))

    if commands.count('D') > len(numList):
        print('error')
        continue
    
    for command in commands:
        if command == 'R':
            front = not front
        else:
            if front:
                del(numList[0])
            else:
                del[numList[-1]]

    printList(numList, front)