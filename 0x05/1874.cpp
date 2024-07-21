/**
 * name:    
 * solved:  N
 */

#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<algorithm>
#define PRE_PROC ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
using namespace std;

void run(){
    /* code HERE */
    int i, j, n, status;
    char ch;

    cin >> n;
    vector<int> v, ret;
    v.reserve(n); // capacity = (n)
    ret.reserve(2*n + 5);
    stack<int> s;
    for (i=0; i<n; i++) {
        cin >> v[i]; // wrong?
    }

    // main logic
    i = 0; // pointer to i = (v input order: index)
    j = 1; // ascending order for input to stack
    status = 1; // game status = continue
    while (status) {
        if (i == n && j == n+1) {
            break;
        }
        while (j <= n && j <= v[i]) {
            s.push(j++);
            ret.emplace_back('+');
        }
        if (s.empty()) {
            status = 0;
            break;
        }
        while (!s.empty() && (i < n) &&  (v[i] == s.top())) {
            s.pop();
            ret.emplace_back('-');
            i++;
        }
        if (!s.empty() && s.top() > v[i]) {
            status = 0;
            break;
        }
    }

    if (!status) {
        cout << "NO\n";
    } else {
        for(char ch : ret) { // wrongable
            cout << ch << '\n';
        }
    }

    return;
}
int main(void){
    PRE_PROC
    run();
    return 0;
}