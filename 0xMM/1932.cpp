/**
 * 1. memoization DP 문제로 접근
 * 2. 최대 크기 10'000, 삼각형 크기 500 이하니까, maximum (2'500'000'000//2)므로
          int형 BOF 걱정 없음
 */

#include <iostream>
#define LMT 504
using namespace std;

int n, ret{-1};
int a1[LMT][LMT], a2[LMT][LMT];

void setIO();

int main(void) {
  setIO();
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < i + 1; j++) {
      cin >> a1[i][j];
      a2[i][j] = -1;
    }
  }

  a2[1][1] = a1[1][1];
  for (int i = n; i > 0; i--) {
    for (int j = 1; j < i + 1; j++) {
      if (i == n) {
        a2[i][j] = a1[i][j];
        continue;
      }

      int L, R;
      L = a2[i + 1][j];
      R = a2[i + 1][j + 1];
      if (L < R) {
        a2[i][j] = a1[i][j] + R;
      } else {
        a2[i][j] = a1[i][j] + L;
      }
    }
  }
  ret = a2[1][1];
  printf("%d", ret);
  return 0;
}

void setIO() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}