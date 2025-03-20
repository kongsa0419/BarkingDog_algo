#include <algorithm>
#include <iostream>
#include <queue>
#define Y first
#define X second
using namespace std;
int mp[30][30], vis[30][30];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int main(void) {
  int n;
  cin >> n;
  string line;
  for (int i = 0; i < n; i++) {
    cin >> line;
    cin.ignore();
    for (int j = 0; j < line.size(); j++) {
      mp[i][j] = line[j] - '0';
    }
  }

  int v{0}, cnt{0};
  queue<pair<int, int>> q;
  vector<pair<int, int>> rec;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (mp[i][j] == 0 || vis[i][j] == 1) continue;
      v++;
      cnt = 1;
      q.push({i, j});
      vis[i][j] = 1;
      while (!q.empty()) {
        auto a = q.front();
        q.pop();
        for (int d = 0; d < 4; d++) {
          int ny = a.Y + dy[d];
          int nx = a.X + dx[d];
          if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
          if (vis[ny][nx] || !mp[ny][nx]) continue;
          cnt++;
          vis[ny][nx] = 1;
          q.push({ny, nx});
        }
      }
      rec.push_back({v, cnt});
    }
  }

  sort(rec.begin(), rec.end(),
       [](const auto& a, const auto& b) { return a.second < b.second; });
  cout << v << '\n';
  for (const auto& a : rec) cout << a.X << '\n';
  return 0;
}