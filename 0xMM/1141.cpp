/**
 * 잘못된 풀이입니다.
 *  */

#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
#define X first
#define Y second

using namespace std;
unordered_set<string> S;  // string, len
vector<string> V;
int main(void) {
  int n;
  int cnt = 0;
  string ln;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> ln;
    S.insert(ln);
  }
  vector<string> data(S.begin(), S.end());
  vector<int> res(data.size(), 0);
  sort(data.begin(), data.end());
  for (int i = 0; i < data.size() - 1; i++) {
    cnt = 0;
    for (int j = i; j < data.size(); j++) {
      if (data[j].substr(0, data[i].size()) == data[i]) cnt++;
    }
    if (cnt > 0) res[i] = cnt;
  }

  cnt = 0;
  for (int i = 0; i < res.size(); i++) {
    if (res[i] == 0) cnt++;
  }

  return 0;
}