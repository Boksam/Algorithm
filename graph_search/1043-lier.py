import sys
from collections import deque

def BFS():
    q = deque() # 진실을 아는 사람 저장
    for p in truth_people[1:]:
        q.append(p)
    
    while q:
        curr = q.popleft()
        person_told_truth[curr] = True
        for party in person_party_list[curr]:
            if not party_told_truth[party]:
                party_told_truth[party] = True
                for person in party_person_list[party]:
                    if not person_told_truth[person]:
                        q.append(person)



N, M = map(int, sys.stdin.readline().split(' '))
# party_told_truth: 진실을 말한 파티, party_person_list: 해당 파티에 참여한 사람 리스트
party_told_truth = [False for i in range(M)]
party_person_list = []

# person_told_truth: 진실을 아는 사람, person_party_list: 해당 사람이 참여한 파티 리스트
person_told_truth = [False for i in range(N + 1)]
person_party_list = [[] for i in range(N + 1)]

truth_people = list(map(int, sys.stdin.readline().split(' ')))

for i in range(M):
    line = list(map(int, sys.stdin.readline().split(' ')))
    party_person_list.append(line[1:])
    for p in line[1:]:
        person_party_list[p].append(i)

BFS()

print(party_told_truth.count(False))