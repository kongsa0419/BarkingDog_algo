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

void run(){
    /* code HERE */
    int n, i, h;
    cin >> n;
    vector<int> v, ret;
    v.reserve(n+1);
    ret.reserve(n+1);
    for (i=1; i<=n; i++) {
        cin >> v[i];
    }
    
    stack<int> s;
    for (i=n; i>=1; i--) {
        while (!s.empty() && s.top() <= v[i]) {
            s.pop();
        }
        if (s.empty()) {
            ret[i] = -1;
        } else if (s.top() > v[i] ) {
            ret[i] = s.top();
        }
        s.push(v[i]);
    }

    for (i=1; i<=n; i++) {
        cout << ret[i] << ' ';
    }
    cout << '\n';
    return;
}
int main(void){
    PRE_PROC
    run();
    return 0;
}