import sys


def paint(y, x, dir, rotate, lim):
  cnt = 1
  
  while True:
    mp[y][x] = cnt
    vis[y][x] = True
    cnt += 1

    if cnt > lim: break
      
    while True:
      ny = y + dy[dir]
      nx = x + dx[dir]
      if ny<0 or nx<0 or ny>=N or nx>=M or vis[ny][nx]:
        dir = (dir + rotate) % 4
      else:
        y = ny; x = nx; break;


        
if __name__ == "__main__":
  (N, M) = tuple(map(int, input().strip().split(' ')))
  dir = input().strip()

  mp = [[0 for _ in range(M)] for _ in range(N)]
  vis = [[False for _ in range(M)] for _ in range(N)]
  # 상 우 하 좌
  dy = [-1, 0, 1, 0]
  dx = [0, 1, 0, -1]
  
  if dir == 'U':
    paint(0, M//2, 2, 1, (N * (M+1) // 2) )
    for r in range(N):
      vis[r][M//2] = False
    paint(0, M//2, 2, -1, (N * (M+1) // 2) )
    
  elif dir == 'D':
    paint(N-1, M//2, 0, 1, (N * (M+1) // 2) )
    for r in range(N):
      vis[r][M//2] = False
    paint(N-1, M//2, 0, -1, (N * (M+1) // 2) )
    
  elif dir == 'L':
    paint(N//2, 0, 1, 1, (N+1) // 2 * M)
    for c in range(M):
      vis[N//2][c] = False
    paint(N//2, 0, 1, -1, (N+1) // 2 * M )
    
  else: # 'R'
    paint(N//2, M-1, 3, 1, (N+1) // 2 * M )
    for c in range(M):
      vis[N//2][c] = False
    paint(N//2, M-1, 3, -1, (N+1) // 2 * M )

  # print
  for r in range(N):
    for c in  range(M):
      print(mp[r][c], end=' ')
    print()