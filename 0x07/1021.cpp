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
    int i, n, k;
    int ret = 0; // shift 연산 총합 (left, right)
    cin >> n >> k;

    deque<int> dq;
    for (i=1; i<=n; i++) {
        dq.emplace_back(i);
    }
    for (i=0; i<k; i++) {
        int x, loc, z;
        cin >> x;
        loc = 0;
        while (loc < dq.size() && dq[loc] != x) {
            loc++;
        } // find index of x (STL deque is indexed)

        if (loc <= (dq.size() / 2)) {  // shift_left is cheaper
            ret += loc;
            while (loc--) {
                z = dq.front();
                dq.pop_front();
                dq.push_back(z);
            }
            dq.pop_front();
        } else {  // shift_right is cheaper
            loc = dq.size() - loc; // how many times to shift
            ret += loc;
            while (loc--) {
                z = dq.back();
                dq.pop_back();
                dq.push_front(z);
            }
            dq.pop_front();
        }
    }
    cout << ret << '\n';
    return;
}

int main(void){
    PRE_PROC
    run();
    return 0;
}