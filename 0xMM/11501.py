import sys

tc = int(input())
for t in range(tc):
  day = int(input())
  arr = list(map(int, sys.stdin.readline().strip().split(' ')))

  res = 0
  k = day-1
  for i in reversed(range(day-1)):
    if arr[i] < arr[k]:
      res += (arr[k]-arr[i])
    else:
      k = i

  print(res)