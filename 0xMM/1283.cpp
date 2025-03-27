/**
 * 1. ' ' 공백을 구분자로 단어를 끊어서 확인하여, 각 단어의 "첫 글자만" 돌며
 * 이미 단축키로 사용중인지 파악한다.
 * 2. 모든 단어의 첫 글자가 단축키로 사용중이라면, 처음부터 입력의 끝까지
 * 순차적으로 사용중이지 않은 문자를 확인한다.
 *
 * **함정은 "첫 글자"까지만 단어별로 확인해야 한다는 점이다.**
 * --> 주관적 생각말고 정확히 시키는대로 하라는 구현문제 특징인가봄
 */
#include <iostream>
#include <string>
#define IO_SYNC                \
  ios::sync_with_stdio(false); \
  cin.tie(0);                  \
  cout.tie(0);
using namespace std;

bool enrolled[26];  // lower-cased (VISIT), false

inline bool is_enrolled(const char& ch) { return enrolled[tolower(ch) - 'a']; }
inline void enroll(const char& ch) { enrolled[tolower(ch) - 'a'] = true; }

void play(const string& line) {
  int offset = -1;  // offset번 위치가 단축키임

  // 단어별 첫글자'만' 탐색
  for (int i = 0; i < line.size(); i++) {
    if (i == 0 || line[i - 1] == ' ') {
      if (isalpha(line[i]) && !is_enrolled(line[i])) {
        enroll(line[i]);
        offset = i;
        break;
      }
    }
  }

  // 단어 첫글자에 shortcut 등록된 경우
  if (offset != -1) {
    for (int i = 0; i < line.size(); i++) {
      if (i == offset) {
        cout << '[' << line[i] << ']';
        continue;
      }
      cout << line[i];
    }
    cout << '\n';
    return;
  }

  // 단어 첫글자가 모두 shortcut에 등록된 경우
  // 왼쪽->오른쪽으로 하나씩 예비 단축키를 탐색해 나감
  for (int i = 0; i < line.size(); i++) {
    if ((offset == -1) && isalpha(line[i]) && !is_enrolled(line[i])) {
      enroll(line[i]);
      offset = i;
      cout << '[' << line[i] << ']';
      continue;
    }
    cout << line[i];
  }
  cout << '\n';
  return;
}

int main(void) {
  IO_SYNC
  int n;
  string line;
  cin >> n;
  cin.ignore();  // '\n'
  for (int i = 0; i < n; i++) {
    getline(cin, line);  // '\n' 무시
    play(line);
  }
  return 0;
}