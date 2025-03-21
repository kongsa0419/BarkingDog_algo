/*

*/
#include <algorithm>
#include <iostream>
#include <unordered_map>
#define X first
#define Y second
using namespace std;

int O[26];

int main() {
  string line;
  unordered_map<char, int> rec;
  cin >> line;
  if (line.size() == 0) return 0;

  sort(line.begin(), line.end());
  int cnt{0};
  do {  // line을 하나씩 순열조합으로 변형시켜줌
    int satis = 1;
    char prev = line[0];
    for (int i = 1; i < line.size(); i++) {
      if (prev == line[i]) {
        satis = 0;  // 행운의문자열x
        break;
      }
      prev = line[i];
    }
    if (satis == 1) cnt++;
  } while (next_permutation(line.begin(), line.end()));

  cout << cnt << '\n';
  return 0;
}