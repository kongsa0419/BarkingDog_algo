import sys

N = int(input())
arr = list(map(int, sys.stdin.readline().strip().split(' ')))
memo = [0] * N
idxarr = [i for i in range(N)]

memo[0] = arr[0]
for i in range(1, N):
  for j in range(0, i):
    if arr[j] < arr[i]:
      memo[i] = max(memo[i], memo[j] + arr[i])
  if memo[i] == 0:
    memo[i] = arr[i]

print(max(memo))