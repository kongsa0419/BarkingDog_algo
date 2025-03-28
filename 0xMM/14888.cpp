/**
 * 1. switch-case 오랜만에 썼더니 break; 안해줘서 해멨고,
 * 2. 구현문제에 뭔가 함정이 있을거같아서 나누기를 직접 정의해줬었는데 언어
 * 특성상 C++에서는 그럴 필요가 없었나봄.
 * 3. play() 호출할 때마다 calc에 nums를 복사하는 과정 삭제하고도 풀 수 있음.
 */
#include <algorithm>
#include <iostream>
using namespace std;

int n;
int sum, sub, mul, dv;   // 1, 2, 3, 4
int mn = 2'147'000'000;  // min, max
int mx = -mn;
int nums[12];
int opers[12];
int calc[12];  //

void play() {  // get max, min
  for (int i = 0; i < n; i++) {
    calc[i] = nums[i];
  }
  int lv = 0;  // idx: 0 ~ n-2까지 돌며 연산자 수행
  while (lv < n - 1) {
    switch (opers[lv]) {
      case 1:  // 더하기
        calc[lv + 1] += calc[lv];
        break;
      case 2:  // 빼기
        calc[lv + 1] = calc[lv] - calc[lv + 1];
        break;
      case 3:  // 곱하기
        calc[lv + 1] *= calc[lv];
        break;
      case 4:  // 나누기
        calc[lv + 1] = (calc[lv] / calc[lv + 1]);
        break;
    }
    lv++;
  }
  if (calc[n - 1] > mx) mx = calc[n - 1];
  if (calc[n - 1] < mn) mn = calc[n - 1];
  return;
}

int main(void) {
  // INPUT
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }
  cin >> sum >> sub >> mul >> dv;
  int idx = 0;
  for (int i = 0; i < sum; i++) opers[idx++] = 1;
  for (int i = 0; i < sub; i++) opers[idx++] = 2;
  for (int i = 0; i < mul; i++) opers[idx++] = 3;
  for (int i = 0; i < dv; i++) opers[idx++] = 4;  // now (idx = n-1)

  // MAIN
  sort(opers, opers + idx);
  do {
    play();
  } while (next_permutation(opers, opers + idx));

  cout << mx << '\n' << mn << '\n';
  return 0;
}