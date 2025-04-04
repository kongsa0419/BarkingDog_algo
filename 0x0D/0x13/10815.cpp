#include <bits/stdc++.h>
#define IOSYNC                 \
  ios::sync_with_stdio(false); \
  cin.tie(0);                  \
  cout.tie(0);
using namespace std;
int n, m, t;
vector<int> cards;

int find(const int& lt, const int& rt, const int& v) {
  if (rt < lt || ((rt == lt) && cards[lt] != v)) return 0;

  int mid = lt + (rt - lt) / 2;
  if (cards[mid] == v) return 1;

  if (cards[mid] < v) return find(mid + 1, rt, v);
  if (cards[mid] > v) return (find(lt, mid - 1, v));
}

int main(void) {
  IOSYNC
  cin >> n;
  cards.reserve(n);
  for (int i = 0; i < n; i++) {
    cin >> m;
    cards.emplace_back(m);
  }

  sort(cards.begin(), cards.end());

  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> t;
    cout << find(0, cards.size() - 1, t) << ' ';
  }
  return 0;
}