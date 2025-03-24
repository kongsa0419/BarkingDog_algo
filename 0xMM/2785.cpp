/**
 * 1. 입력을 mean heap(H)에 받는다.
 * 2. mean heap의 가장 작은 체인 고리수를 M이라 하자.
 *      while(M>=1 && H.size()>=2) {
 *          // H에서 정수 두개를 꺼내어 더하고, 그 값을 새로 H에 넣는다.
 *          // M--
 *      }
 * 잘못된 접근... 2 pointer 알고리즘으로 다시 풀어보기
 * 반례
    6
    1 1 1 100 100 100
    ==>3 (나는 4)
 *
 */

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

long long n, ret{0};
priority_queue<long long, vector<long long>, greater<long long>>
    pq;  // mean heap

int main(void) {
  cin >> n;
  long long k;
  for (long long i = 0; i < n; i++) {
    cin >> k;
    pq.push(k);
  }

  if (pq.empty()) {
    cout << "error\n";
    exit(1);
  }

  long long e1, e2;  // element
  long long M = pq.top();
  pq.pop();
  while (M > 0 && pq.size() >= 2) {
    M--;
    ret++;  //
    e1 = pq.top();
    pq.pop();
    e2 = pq.top();
    pq.pop();
    pq.push(e1 + e2 + 1);
    if (M == 0) {
      M = pq.top();
      pq.pop();
    }
  }

  if (!pq.empty()) {
    pq.pop();
    ret++;
  }
  cout << ret << '\n';
  return 0;
}