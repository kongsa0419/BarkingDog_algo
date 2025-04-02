#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

const int ROW = 12;
const int COL = 6;
string mp[ROW];
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

bool safe_idx(int y, int x) {
  if (y < 0 || y >= ROW || x < 0 || x >= COL) return false;
  return true;
}

int main(void) {
  int turn = 0;  // 블록 채우는 횟수

  // input
  for (int i = 0; i < ROW; i++) cin >> mp[i];

  while (true) {
    // BFS
    queue<pair<int, int>> Q;   // BFS
    deque<pair<int, int>> GC;  // Garbage Collector
    bool vis[ROW][COL];
    for (int i = 0; i < ROW; i++) fill(vis[i], vis[i] + COL, false);

    for (int i = 0; i < ROW; i++) {
      for (int j = 0; j < COL; j++) {
        if (mp[i][j] == '.' || vis[i][j]) continue;

        Q.push({i, j});
        GC.push_back({i, j});  // tracing
        vis[i][j] = true;
        int cnt = 1;
        while (!Q.empty()) {
          int y = Q.front().X;
          int x = Q.front().Y;
          Q.pop();
          for (int d = 0; d < 4; d++) {
            int ny = y + dy[d];
            int nx = x + dx[d];
            if (!safe_idx(ny, nx) || vis[ny][nx]) continue;
            if (mp[i][j] == mp[ny][nx]) {
              vis[ny][nx] = true;
              Q.push({ny, nx});
              GC.push_back({ny, nx});
              cnt++;
            }
          }
        }

        // GC에는 다음 round에 삭제될 좌표만 저장해둔다.
        if (cnt < 4) {
          while (cnt--) {
            GC.pop_back();
          }
        }
      }
    }

    // 바뀐게 없으면
    if (GC.empty()) break;

    // GC에 담긴 것들을 다 지우기 위해 '.'으로 치환
    while (!GC.empty()) {
      mp[GC.front().X][GC.front().Y] = '.';
      GC.pop_front();
    }

    // Align (중력 처리)
    stack<char> S;
    for (int j = 0; j < COL; j++) {
      for (int i = 0; i < ROW; i++) {
        if (mp[i][j] != '.') {
          S.push(mp[i][j]);
          mp[i][j] = '.';
        }
      }
      int i = ROW - 1;
      while (!S.empty()) {
        mp[i--][j] = S.top();
        S.pop();
      }
    }

    turn++;  // 한 차례가 돌았음 (중요)
  }

  cout << turn << '\n';
  return 0;
}