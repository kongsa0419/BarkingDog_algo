/*
그래프에서 상근(1)을 기준으로 depth:2 만큼만 bfs하는 문제.
BFS로 풀이
1. 상근이(1)과 연결된 친구를 방문하고,
2. 딱 한 다리만 더 방문한다.(친구의 친구)
*/

#include <bits/stdc++.h>
using namespace std;

int main(void) {
  // input
  int n, m, f, t;
  vector<int> ll[501];
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> f >> t;
    ll[f].push_back(t);
    ll[t].push_back(f);
  }

  // BFS
  int invite = 0;
  queue<pair<int, int>> Q;  // {src, level}
  vector<bool> vis(n + 3, false);
  Q.push({1, 0});  // 상근이로부터 출발하며, 레벨은 0
  vis[1] = true;
  while (!Q.empty()) {
    int src, lv;
    tie(src, lv) = Q.front();
    Q.pop();
    if (lv >= 2) break;  // 친구의 친구의 친구가 되어서 이후부터는 무시
    for (int j = 0; j < ll[src].size(); j++) {
      int dst = ll[src].at(j);
      if (vis[dst]) continue;
      vis[dst] = true;
      Q.push({dst, lv + 1});
      ++invite;
    }
  }

  cout << invite << '\n';
}