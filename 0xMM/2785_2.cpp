/** PS: greedy
 * mthd: Two pointer
 */

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

long long n;
vector<int> rings;

int main(void) {
  cin >> n;
  rings.reserve(n);
  int k;
  for (int i = 0; i < n; i++) {
    cin >> k;
    rings.emplace_back(k);
  }
  sort(rings.begin(), rings.end(), less<int>());  // ascending

  int sp{0}, ep = (rings.size() - 1);  // start, end point
  int cnt = 0;
  k = rings[sp];
  while (sp < ep - 1) {
    rings[ep - 1] += rings[ep];
    ep--;
    cnt++;
    if (--k == 0) k = rings[++sp];
  }
  if (sp < ep && k > 0) cnt++;
  cout << cnt;
  return 0;
}
