'''
Backtracking으로 풀게되면 N ^ N으로 시간초과.
DP를 사용하여 N^2으로 시간 줄임
'''

import sys

if __name__ == "__main__":
  # input
  N = int(input())
  arr = list(map(int, sys.stdin.readline().strip().split(' ')))
  arr.insert(0, 0) # index 0에 0 insert
  memo = [0 for _ in range(N+1)]
  
  # init
  result = 100_000_000

  # DP
  for i in range(1,N+1):
    memo[i] = arr[i]
    for j in range(1, i):
      memo[i] = min(memo[i], memo[i-j] + memo[j])
    
  # result
  print(memo[N])