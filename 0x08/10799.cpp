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
#define X first
#define Y second

using namespace std;

void run(){
    /* code HERE */
    string s;
    deque<pair<int,int>> dq; // {idx, rasor count}
    int res = 0;

    cin >> s;
    for (int i=0; i<s.length(); i++) {
        if (s[i] == '(') {
            dq.push_back({i, 0}); // has no rasor upon this layer
        } else if (s[i] == ')' && !dq.empty() && dq.back().X == i-1) { // rasor 
            dq.pop_back();
            if (!dq.empty()) dq.back().Y += 1; // raosr count
        } else { // end of top layer steel stick
            if (!dq.empty()) {
                int rasor_cnt = dq.back().Y;
                res += (rasor_cnt + 1);
                dq.pop_back();
                if (!dq.empty()) {
                    dq.back().Y += rasor_cnt; // accumulate rasor count
                }
            }
        }
    }
    cout << res << '\n';
    return;
}
int main(void){
    PRE_PROC
    run();
    return 0;
}