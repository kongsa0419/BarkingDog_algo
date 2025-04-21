import sys

if __name__ == "__main__":
  input = sys.stdin.readline
  N = int(input())
  K = int(input())
  arr = set(map(int, input().strip().split(' '))) # 중복 제거
  arr = list(arr)
  arr.sort()

  res = 0
  blanks = list()
  for i in range(1, len(arr)):
    blanks.append(arr[i] - arr[i-1])
  blanks.sort()
  for _ in range(1,K):
    if blanks:
        blanks.pop()

  if blanks:
    res = sum(blanks)
  print(res)