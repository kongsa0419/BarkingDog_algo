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
    int n, m, i, x, res;
    res = 0;
    cin >> n >> m;
    deque<int> dq;
    for (i=1; i<=n; i++) dq.push_back(i);
    while (m--) {
        cin >> x;
        int idx = find(dq.begin(), dq.end(), x) - dq.begin();
        while (!dq.empty() && dq.front() != x) {
            if (idx > dq.size() - idx) {
                dq.push_front(dq.back());
                dq.pop_back();
            } else {
                dq.push_back(dq.front());
                dq.pop_front();
            }
            res++;
        }
        if (!dq.empty()) dq.pop_front();
    }
    cout << res << '\n';
    return;
}
int main(void){
    PRE_PROC
    run();
    return 0;
}