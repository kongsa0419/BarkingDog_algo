#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
int N, M, dist[103][103];
vector<int> mp[103];  // input
int minkv = 2'147'000'000;
int winner = -1;  // output
bool visit[103];

void input() {
  cin >> N >> M;
  int a, b;
  for (int i = 0; i < M; i++) {
    cin >> a >> b;
    mp[a].push_back(b);
    mp[b].push_back(a);
  }
}

void FW() {
  for (int i = 1; i <= N; i++) {  // i = src
    fill(visit, visit + 103, false);
    queue<pair<int, int>> Q;  // <dst, level>
    for (auto a : mp[i]) {
      Q.push({a, 1});
      dist[i][a] = 1;
      visit[a] = true;
    }
    visit[i] = true;
    // BFS
    while (!Q.empty()) {
      int src, lv;
      tie(src, lv) = Q.front();
      Q.pop();
      for (auto a : mp[src]) {  // TIME COMPLEXITY 문제 가능성
        if (visit[a]) continue;
        dist[i][a] = lv + 1;
        visit[a] = true;
        Q.push({a, lv + 1});
      }
    }

    int k = 0;  // (temporary) kevin-bakan
    for (int j = 1; j <= N; j++) {
      if (i == j) continue;
      k += dist[i][j];
    }
    if (k < minkv) {
      minkv = k;
      winner = i;
    }
  }
}

int main(void) {
  input();
  FW();
  cout << winner << '\n';
  return 0;
}