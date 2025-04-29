'''
6개줄, P개 프렛
움직임: 프렛을 한번 누르거나 떼는것

프렛룰: 프렛을 중복하여 누를 경우 가장 높은 프렛만 유효
프렛을 가장 적게 누르는 (손가락 움직임) 회수 구하시오.
'''
import sys

starr = [[] for _ in range(7)] # stack array
result = 0

input = sys.stdin.readline
(N, P) = map(int, input().strip().split(' '))
for i in range(N):
  (a,b) = map(int, input().strip().split(' '))
  if not starr[a]: # empty
    starr[a].append(b)
    result += 1
  else: # not empty
    while starr[a] and starr[a][-1] > b:
      starr[a].pop()
      result += 1
    if starr[a] and starr[a][-1] == b:
      continue
    starr[a].append(b)
    result += 1

print(result)