/**
 * 왜 이건 메모리초과가 날까?
 * 디버깅용으로 unordered_set 추가했었는데 (나만 보려고) -=> 이것이 문제엿음.
 */

#include <algorithm>
#include <iostream>
#include <unordered_map>
#define X first
#define Y second
using namespace std;

string line;
int ret{0};
unordered_map<char, int> rec;

void BT(string& str) {
  if (str.length() == line.size()) {
    ret++;
    return;
  }

  char prev = str.back();
  for (auto it = rec.begin(); it != rec.end(); it++) {
    char next = it->X;
    int qtt = it->Y;
    if (qtt <= 0) continue;
    if (prev == next) continue;
    rec[next]--;
    str.push_back(next);
    BT(str);
    rec[next]++;
    str.pop_back();
  }
}

int main(void) {
  cin >> line;

  char ch;
  for (int i = 0; i < line.size(); i++) {
    ch = line[i];
    if (rec.find(ch) != rec.end()) {
      rec[ch]++;
    } else {
      rec.insert({ch, 1});
    }
  }

  for (auto it = rec.begin(); it != rec.end(); it++) {
    ch = it->X;
    rec[ch]--;
    string S = string(1, ch);  // "" + ch; 하니까 오류났었음.
    BT(S);
    rec[ch]++;
  }

  cout << ret << '\n';
  return 0;
}