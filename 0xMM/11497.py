import sys
from collections import deque

TC = int(input().strip())
while True:
  TC -= 1
  if TC < 0: break;
  N = int(input())
  arr = list(map(int, sys.stdin.readline().strip().split(' ')))
  arr.sort()

  dq = deque()
  push_front = True
  for e in arr:
    if push_front:
      dq.appendleft(e)
      push_front = False
    else:
      dq.append(e)
      push_front = True
  res = 0
  sz = len(dq)
  for i in range(sz):
    v1 = abs(dq[i] - dq[(i-1) % sz])
    v2 = abs(dq[i] - dq[(i+1) % sz])
    res = max(v1, v2, res)
  print(res)