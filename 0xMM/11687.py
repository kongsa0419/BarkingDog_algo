# count '0' in  val!(Factorial)
def bin_search(k):
  cnt = 0
  while k>=5:
    cnt += (k//5)
    k //= 5
  return cnt
  
# binary search
if __name__ == "__main__":
  result = -1
  M = int(input())
  
  lt = 0
  rt = 5 * M
  while lt <= rt:
    mid = lt + (rt-lt) // 2
    cnt = bin_search(mid)
    if cnt < M:
      lt = mid + 1
    # elif cnt == M: 지양.
    # M=6 mid = 25, 26일 경우 26또한 정답처리돼서 오류
    else:
      if cnt == M: # 이렇게 처리해줘야함.
        result = mid
      rt = mid - 1
  print(result)