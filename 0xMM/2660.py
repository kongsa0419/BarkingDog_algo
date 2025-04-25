import sys
from collections import deque

# input
N = int(input())
dist = [[float('inf') for _ in range(N+1)] for _ in range(N+1)]
G = [list() for _ in range(N+1)] # 연결리스트 (1 ~ N)
cand = list()

while True:
  (a,b) = tuple(map(int, input().strip().split(' ')))
  if a==-1 and b==-1:
    break
  G[a].append(b)
  G[b].append(a)

# bfs x N
for p in range(1, N+1):
  vis = [False for _ in range(N+1)]
  dq = deque() # Queue

  vis[p] = True
  viscnt = 1
  dist[p][p] = 0
  dq.append((p,0)) # 자기 자신
  while dq:
    (v, dd) = dq.popleft()
    for nv in G[v]:
      if vis[nv]: continue;
      dq.append((nv, dd+1))
      dist[p][nv] = dd+1
      vis[nv] = True
  cand.append( (p, max(dist[p][1:N+1])) )

# 출력 전처리
cand.sort(key=lambda x:x[1])
score = cand[0][1]
for i in range(len(cand)):
  if score != cand[i][1]:
    cand = cand[0:i]
    break
# 출력
print(cand[0][1] ,len(cand)) # 회장후보점수, 회장후보수
for i in range(len(cand)):
  print(cand[i][0], end=' ')