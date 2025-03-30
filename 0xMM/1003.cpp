#include <iostream>
#define IOSYNC                 \
  ios::sync_with_stdio(false); \
  cin.tie(0);                  \
  cout.tie(0);
using namespace std;

int fib[42][2];
int TC;
void init() {
  fib[0][0] = 1;
  fib[0][1] = 0;
  fib[1][0] = 0;
  fib[1][1] = 1;

  for (int i = 2; i <= 40; i++) {
    fib[i][0] = fib[i - 1][0] + fib[i - 2][0];
    fib[i][1] = fib[i - 1][1] + fib[i - 2][1];
  }
}
int main(void) {
  IOSYNC
  cin >> TC;
  init();
  while (TC--) {
    int n;
    cin >> n;
    cout << fib[n][0] << ' ' << fib[n][1] << '\n';
  }
  return 0;
}