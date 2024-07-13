/**
 * name:    
 * solved:  N
 */
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
void print_stack(stack<pair<int,int>>& org) {
  stack<pair<int,int>> tmp;
  while (!org.empty()) {
    tmp.push(org.top());
    org.pop();
  }
  cout << "[(X,Y): ";
  while (!tmp.empty()) {
    cout << tmp.top().X << ',' << tmp.top().Y << ' ';
    org.push(tmp.top());
    tmp.pop();
  }
  cout << "]\n";
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  stack<pair<int, int>> S;
  long long ans = 0;
  while (n--) {
    int h;
    cin >> h;
    int cnt = 1;
    while (!S.empty() && S.top().X <= h) {
      ans += S.top().Y;
      if (S.top().X == h) cnt += S.top().Y; // <= 아님?
      S.pop();
    }
    // print stack list
    print_stack(S);
    if (!S.empty()) ans++;
    S.push({h, cnt});
  }
  cout << ans;
}