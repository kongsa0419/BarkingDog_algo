import sys

DIV = 1_234_567

# 1000 x 10 array
memo = [[-1 for i in range(10)] for j in range(1001)]
results = [-1 for i in range(1001)]
mp = {
  0:[7],
  1:[2,4],
  2:[1,3,5],
  3:[2,6],
  4:[1,5,7],
  5:[2,4,6,8],
  6:[3,5,9],
  7:[0,4,8],
  8:[5,7,9],
  9:[6,8]
}


def play(depth, lim):
  while results[depth] != -1:
    depth += 1
    
  while depth <= lim:
    for i in range(10):
      if i == 0:
        memo[depth][i] = memo[depth-1][7] % DIV
        continue
      memo[depth][i] = sum(memo[depth-1][j] for j in mp[i]) % DIV
    
    # get result on results[] and print (dbg)
    results[depth] = sum(memo[depth]) % DIV
    
    # repeat
    depth += 1
    
# init
for i in range(10):
  memo[1][i] = 1
results[1] = 10

# MAIN
tc = int(input())
while tc > 0:
  N = int(input())
  if results[N] == -1:
    play(1, N)
  print(results[N])
  
  tc -= 1
  if tc == 0:
    break