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
void parse (const string& s, deque<int>& dq) {
    int x;
    for (int i=1; i<s.size()-1; i++) {
        if (s[i] == ',') {
            dq.push_back(x);
            x = 0;
        } else {
            x = (x * 10) + (s[i] - '0');
        }
    }
    if (x != 0) dq.push_back(x); 
}

void playgame() {
    string cmd, arr;
    int n;
    bool flipped = false;
    cin >> cmd >> n >> arr;
    
    deque<int> dq;
    parse(arr, dq);
    
    for (int i=0; i<cmd.size(); i++) {
        if (cmd[i] == 'R') {
            flipped = !flipped;
        } else {
            if (dq.empty()) {
                cout << "error\n";
                return;
            }
            if (flipped) dq.pop_back();
            else dq.pop_front();
        }
    }

    if (flipped) reverse(dq.begin(), dq.end());
    cout << '[';
    for (int i=0; i<dq.size(); i++) {
        cout << dq[i];
        if (i+1 != dq.size()) cout << ',';
    }
    cout << "]\n";
}

void run(){
    /* code HERE */
    int k;
    cin >> k;
    while (k--) {
        playgame();
    }
    return;
}
int main(void){
    PRE_PROC
    run();
    return 0;
}
