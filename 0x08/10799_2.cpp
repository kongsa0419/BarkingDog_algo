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
    char ch;
    deque<pair<int,int>> dq; // {idx, rasor}
    int i=0;
    int res = 0;
    while (cin.get(ch) && ch != '\n') {
        if (ch == '(') {
            dq.push_back({i,0}); // has no rasor
        } else if (ch == ')' && dq.back().X == i-1) { // rasor 
            dq.pop_back();
            if (!dq.empty()) dq.back().Y++;
        } else { // end of top layer steel stick
            if (!dq.empty()) {
                int rasor_cnt = dq.back().Y;
                res += (rasor_cnt + 1);
                dq.pop_back();
                if (!dq.empty()) {
                    dq.back().Y += rasor_cnt;
                }
            }
        }
        i++;
    }
    cout << res << '\n';
    return;
}
int main(void){
    PRE_PROC
    run();
    return 0;
}