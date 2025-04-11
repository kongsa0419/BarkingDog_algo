/*
R,C가 20 이하로 작고, 각 단어의 길이가 최소 2인 점을 고려하면
Brute Force로 풀 수 있다.
*/
#include <iostream>
#include <set>  // auto-sorted (Red-black tree)
#include <string>
using namespace std;
int r, c;
string puzzle[25];
set<string> words;

void input() {
  cin >> r >> c;
  cin.ignore();  // buffer '\n'
  for (int i = 0; i < r; i++) {
    cin >> puzzle[i];
  }
}
void run() {
  bool searching;
  int from;
  string tmp;
  // 가로 탐색
  for (int i = 0; i < r; i++) {
    searching = false;
    for (int j = 0; j < c; j++) {
      if (puzzle[i][j] == '#') {
        if (searching) {
          tmp = puzzle[i].substr(from, j - from);
          words.insert(tmp);
          searching = false;
          continue;
        }
      } else {
        if (!searching) {
          from = j;
          searching = true;
        }
      }
    }
    if (searching) {
      tmp = puzzle[i].substr(from, c - from);
      words.insert(tmp);
      searching = false;
    }
  }

  // 세로 탐색
  for (int i = 0; i < c; i++) {
    searching = false;
    for (int j = 0; j < r; j++) {
      if (puzzle[j][i] == '#') {
        if (searching) {  // save puzzle [from][i] ~ [j][i] into set
          tmp.clear();    // init
          for (int k = from; k < j; k++) {
            tmp.push_back(puzzle[k][i]);
          }
          words.insert(tmp);
          searching = false;
        }
      } else {
        if (!searching) {
          searching = true;
          from = j;
        }
      }
    }
    if (searching) {
      tmp.clear();
      for (int k = from; k < r; k++) {
        tmp.push_back(puzzle[k][i]);
      }
      words.insert(tmp);
      searching = false;
    }
  }

  for (const auto& a : words) {
    if (a.size() >= 2) {
      cout << a << '\n';
      return;
    }
  }
}

int main(void) {
  input();
  run();
  return 0;
}