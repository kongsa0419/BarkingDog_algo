#include <cmath>
#include <iostream>
#include <string>
using namespace std;
void hanoi(int n, int src, int dst) {
  if (n == 1) {
    cout << src << ' ' << dst << '\n';
    return;
  }
  int tmp;
  for (int i = 1; i <= 3; i++) {
    if (i != src && i != dst) {
      tmp = i;
      break;
    }
  }
  hanoi(n - 1, src, tmp);
  cout << src << ' ' << dst << '\n';
  hanoi(n - 1, tmp, dst);
}

int main(void) {
  int n;
  cin >> n;

  string res = to_string(pow(2, n));
  int x = res.find('.');
  res = res.substr(0, x);

  if (res[res.size() - 1] == '0') {  // - 1 처리
    x = res.size() - 1;
    for (int i = res.size() - 1; i >= 0; i--) {
      if (res[i] > '0') break;
      x--;
    }
    res[x]--;
    for (int i = x + 1; i < res.size() - 1; i++) {
      res[i] = '9';
    }
  } else {
    res[res.size() - 1]--;
  }

  cout << res << '\n';
  if (n <= 20) {
    hanoi(n, 1, 3);
  }
  return 0;
}