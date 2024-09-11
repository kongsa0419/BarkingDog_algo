/**
 * name:    
 * solved:  N
 */

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#define PRE_PROC ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
using namespace std;

int min_idx(deque<int>& dq) {
    int idx = 0, min = 2'147'000'000;
    for (int i=0; i<dq.size(); i++) {
        if (min > dq[i]) {
            min = dq[i];
            idx = i;
        }
    }
    return idx;
}
void run(){
    /* code HERE */
    int N, L, x;
    cin >> N >> L;
    deque<int> v;
    // priority_queue<pair<int, int>, vector<pair<int,int>>, greater<int>> pq; // min heap
    for (int i=0; i<N; i++) {
        cin >> x;
        v.push_back(x);
        int idx = min_idx(v);
        cout << v[idx] << ' ';
        if (v.size() == L) {
            v.pop_front();
        }
    }
    return;
}
int main(void){
    PRE_PROC
    run();
    return 0;
}