/**
 * name:    
 * solved:  N
 */

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<stack>
#define PRE_PROC ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
using namespace std;

#define X first
#define Y second

void run(){
    /* code HERE */
    int n, i, h, cnt;
    long long sum = 0;
    stack<pair<int, int>> s; /* {height, 키에 따른 사람수} */
    
    cin >> n;
    for (i=0; i<n; i++) {
      cin >> h;
      cnt = 1;
      while (!s.empty() && s.top().X <= h) { /* 어차피 h보다 작은 사람들은 h뒤에 올 사람들을 볼 수 없으므로 제거 */
        sum += s.top().Y;
        if (s.top().X == h) {
          cnt += s.top().Y; /* 중복된 수를 관리해줘야 계산량이 줆 */
        }
        s.pop();
      }
      if (!s.empty()) sum++;
      s.push({h, cnt});
    }

    cout << sum << '\n';
    return;
}
int main(void){
    PRE_PROC
    run();
    return 0;
}