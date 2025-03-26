#include <iostream>
using namespace std;

int M, N, X, Y;
int play() {
  cin >> M >> N >> X >> Y;
  int a, b, jump, offset, cnt;  // x,y 계산값
  int year = 0, flag = -1;      // flag : {case #1, case #2}
  if (M > N) {
    jump = M;
    offset = X;
    flag = 1;
  } else {
    jump = N;
    offset = Y;
    flag = 2;
  }

  cnt = 0;
  int LIMIT = M * N;
  while (true) {
    year = (jump * cnt) + offset;
    if (year > LIMIT) break;
    a = (year % M);
    b = (year % N);
    if (a == 0) a = M;
    if (b == 0) b = N;
    if (a == X && b == Y) return year;
    ++cnt;
  }
  return -1;
}
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int tc;
  cin >> tc;
  while (tc-- > 0) {
    cout << play() << '\n';
  }
  return 0;
}