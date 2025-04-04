#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> mp;
int n, m, k;
int mx = -1, pics = 0;
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

int safe(const int& y, const int& x) {
  if (y < 0 || x < 0 || y >= n || x >= m) return false;
  return true;
}

int main(void) {
  // input
  cin >> n >> m;
  mp.resize(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> k;
      mp[i][j] = k;
    }
  }

  // BFS
  queue<pair<int, int>> Q;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!mp[i][j]) continue;

      pics++;  // 그림 1개 추가
      int cnt = 1;
      Q.push({i, j});
      mp[i][j] = 0;
      while (!Q.empty()) {
        int y, x;
        tie(y, x) = Q.front();
        Q.pop();
        for (int d = 0; d < 4; d++) {
          int ny = y + dy[d];
          int nx = x + dx[d];
          if (!safe(ny, nx) || !mp[ny][nx]) continue;
          Q.push({ny, nx});
          ++cnt;
          mp[ny][nx] = 0;
        }
      }

      if (cnt > mx) mx = cnt;  // 가장 큰 그림 갱신
    }
  }

  if (pics == 0) mx = 0;
  cout << pics << '\n' << mx << '\n';
  return 0;
}