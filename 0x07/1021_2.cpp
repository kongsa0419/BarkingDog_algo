/**
 * name:    
 * solved:  N
 */

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<stack>
#include<deque>
#define PRE_PROC ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
using namespace std;

void run(){
    /* code HERE */
    int n, k;
    cin >> n >> k;
    deque<int> dq;
    for (int i=1; i<=n; i++) dq.push_back(i);
    int ans = 0;
    while (k--) {
        int x;
        cin >> x;
        int idx = find(dq.begin(), dq.end(), x) - dq.begin(); //
        while (dq.front() != x) {
            if (idx <= (dq.size() - idx)) {
                dq.push_back(dq.front());
                dq.pop_front();
            } else {
                dq.push_front(dq.back());
                dq.pop_back();
            }
            ans++;
        }
        dq.pop_front();
    }
    cout << ans << '\n';
    return;
}

int main(void){
    PRE_PROC
    run();
    return 0;
}