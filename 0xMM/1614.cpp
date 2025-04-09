/*
1  2  3  4  5
-  -  -  -  -
1  2  3  4  5
9  8  7  6  \
\ 10 11 12 13
1716 15 14  \
\ 18 19 20 21

각 열마다 패턴의 등차수열이 보인다. 이를 활용하여 푼다.
*/

#include <iostream>
using namespace std;
int main(void) {
  int num, cnt;  // 아픈 손가락, 접는 횟수
  cin >> num >> cnt;

  if (cnt == 0) {  // 종료조건
    cout << (num - 1) << '\n';
    return (0);
  }

  long long call;              // (cnt+1) 만큼 접었을 때 부를 수 있는 최대 수
  if (num == 1 || num == 5) {  // 한번 접을때마다 +8
    call = num + (8 * cnt);
  } else if (num == 2) {  // {6,2,6,2,6,2...} 순으로 더해감
    int a6, a2;           // adder 6 or 2
    a6 = (cnt / 2) + (cnt % 2);
    a2 = a6;
    if (cnt % 2) a2--;
    call = num + (a6 * 6) + (a2 * 2);
  } else if (num == 4) {  // {2, 6, 2, 6...} 순으로 더해감
    int a6, a2;           // adder 6 or 2
    a2 = (cnt / 2) + (cnt % 2);
    a6 = a2;
    if (cnt % 2) a6--;
    call = num + (a6 * 6) + (a2 * 2);
  } else {  // num == 3
    call = num + (4 * cnt);
  }

  cout << (call - 1) << '\n';
  return 0;
}