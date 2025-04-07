#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> buffer(10, 0);
void BT(int num, int idx) {
  if (idx == m) {  // escape
    for (int j = 0; j < m; j++) {
      cout << buffer[j] << ' ';
    }
    cout << '\n';
    return;
  }

  for (int j = num; j <= n; j++) {
    buffer[idx] = j;
    BT(j, idx + 1);
  }
}
int main(void) {
  cin >> n >> m;
  BT(1, 0);  // 1보다 크거나 같은 수에 대해, 0개를 선택하였음
  return 0;
}