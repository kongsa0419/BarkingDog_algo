/*
  Top-down 방식으로 접근 시도
  공간복잡도를 줄여보자.
*/

#include <iostream>
#define LMT 504
using namespace std;

int n, ret{-1};
int a1[LMT][LMT];

int main(void) {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < i + 1; j++) {
      cin >> a1[i][j];
    }
  }
  if (n == 1) {
    printf("%d", a1[1][1]);
    return 0;
  }
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      if (j == 1) {
        a1[i][j] += a1[i - 1][j];
      } else if (j == i) {
        a1[i][j] += a1[i - 1][j - 1];
      } else {
        if (a1[i - 1][j - 1] >= a1[i - 1][j]) {
          a1[i][j] += a1[i - 1][j - 1];
        } else {
          a1[i][j] += a1[i - 1][j];
        }
      }
      if (i == n) {
        if (ret < a1[i][j]) ret = a1[i][j];
      }
    }
  }
  printf("%d", ret);
  return 0;
}