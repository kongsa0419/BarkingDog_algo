#include <bits/stdc++.h>

using namespace std;

int m, n, k;
int mp[103][103], vis[103][103];
vector<int> areas;
queue<pair<int, int>> Q;
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

inline bool safe(const int& r, const int& c) {
  return !(r < 0 || r >= m || c < 0 || c >= n);
}

void input() {
  cin >> m >> n >> k;
  // init map
  for (int i = 0; i < m; i++) std::fill(mp[i], mp[i] + n, 1);
  int a, b, c, d;
  for (int i = 0; i < k; i++) {
    cin >> a >> b >> c >> d;
    // paint map : (a,b) ~ (c,d)
    for (int row = b; row < d; row++) {
      for (int col = a; col < c; col++) {
        mp[row][col] = 0;  // 오히려 빈 공간만 1로 남김 (BFS 위함)
      }
    }
  }
}

void BFS() {
  int size;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (!mp[i][j] || vis[i][j]) continue;
      vis[i][j] = 1;
      Q.push({i, j});
      size = 1;
      while (!Q.empty()) {
        int r, c;
        tie(r, c) = Q.front();
        Q.pop();
        for (int d = 0; d < 4; d++) {
          int nr = r + dy[d];
          int nc = c + dx[d];
          if (!safe(nr, nc)) continue;
          if (!mp[nr][nc] || vis[nr][nc]) continue;
          ++size;
          Q.push({nr, nc});
          vis[nr][nc] = 1;
        }
      }
      // end of the block
      areas.push_back(size);
    }
  }
}

int main(void) {
  input();
  BFS();
  std::sort(areas.begin(), areas.end());    // ascending
  cout << areas.size() << '\n';             // 1
  for (int i = 0; i < areas.size(); i++) {  // 2
    cout << areas.at(i) << ' ';
  }
  return 0;
}