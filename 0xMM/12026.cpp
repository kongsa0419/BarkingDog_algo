#include <algorithm>
#include <iostream>
#include <stack>
#include <tuple>
#include <vector>
#define INT_MAX 0x7FFFFFFF
using namespace std;

int n, res = INT_MAX;
string line;

int main(void) {
  cin >> n;
  cin >> line;
  vector<int> dists(n + 3, INT_MAX);
  dists[0] = 0;
  for (int i = 0; i < n; i++) {
    if (line[i] == 'B') {
      for (int j = i + 1; j < n; j++) {
        if (line[j] == 'O') {
          dists[j] = std::min(dists[j], dists[i] + (j - i) * (j - i));
        }
      }
    } else if (line[i] == 'O') {
      for (int j = i + 1; j < n; j++) {
        if (line[j] == 'J') {
          dists[j] = std::min(dists[j], dists[i] + (j - i) * (j - i));
        }
      }
    } else {
      for (int j = i + 1; j < n; j++) {
        if (line[j] == 'B') {
          dists[j] = std::min(dists[j], dists[i] + (j - i) * (j - i));
        }
      }
    }
  }

  res = dists[n - 1];
  if (res == INT_MAX)
    cout << -1 << '\n';
  else
    cout << res << '\n';
  return 0;
}