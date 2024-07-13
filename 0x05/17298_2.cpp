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
#define LIMIT 1'000'005
using namespace std;

void run(){
    /* code HERE */
    int n, i, x;
    cin >> n;
    vector<int> v, ret;
    v.reserve(n);
    ret.reserve(n);
    for (i=0; i<n; i++) {
        cin >> v[i];
    }
    
    stack<int> s;
    s.push(LIMIT);
    for (i=n-1; i>=0; i--) {
        while(!s.empty() && s.top() <= v[i]) {
            s.pop();
        }
        ret[i] = (s.top() == LIMIT) ? -1 : s.top();
        s.push(v[i]);
    }
    for (i=0; i<n; i++) {
        cout << ret[i] << ' ';
    }
    return ;
}
int main(void){
    PRE_PROC
    run();
    return 0;
}