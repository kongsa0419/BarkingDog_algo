/**
 * name:    
 * solved:  N
 */

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<deque>
#include<stack>
#define PRE_PROC ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
using namespace std;

void parse(string& arr, deque<int>& dq) {
    int n = 0;
    for (int i=1; i<arr.length(); i++) {
        if (arr[i] == ',' || arr[i] == ']'){
            if (n != 0) dq.push_back(n);
            n = 0;
            continue;
        }
        n = 10 * n + (arr[i] - '0');
    }
    return;
}

void playgame() {
    string cmd, arr;
    int n, i, x, err;
    deque<int> dq;
    cin >> cmd;
    cin >> n;
    cin >> arr;
    parse(arr, dq);
    i = x = err = 0;  /* x = 1 ? reversed*/
    while (i < cmd.length() && !err) {
        if (cmd[i] == 'D') {
            if (dq.empty()) {
                err = 1;
                break; //error
            } else if (x) {
                dq.pop_back();
            } else {
                dq.pop_front();
            }
        } else {
            x = !x; // flip
        }
        i++;
    }

    if (err) {
        cout << "error\n";
    } else {
        if (x) reverse(dq.begin(), dq.end());
        cout << '[';
        while (!dq.empty()) {
            cout << dq.front();
            dq.pop_front();
            if (!dq.empty()) cout << ',';
        }
        cout << "]\n";
    }
    return;
}

void run(){
    /* code HERE */
    int TC;
    cin >> TC;
    while (TC--) {
        playgame();
    }
    return;
}
int main(void){
    PRE_PROC
    run();
    return 0;
}