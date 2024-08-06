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
using namespace std;

int parse (string& str) {
    bool valid = true;
    stack<char> S;
    for(int i=0; i<str.length(); i++) {
        if (str[i] == '[' || str[i] == '(') {
            S.push(str[i]);
        } else if (str[i] == ']') {
            if (!S.empty() && S.top() == '[') {
                S.pop();
            } else {
                valid = false;
            }
        } else if (str[i] == ')') {
            if (!S.empty() && S.top() == '(') {
                S.pop();
            } else {
                valid = false;
            }
        } else {}
        
        if (!valid) break;
    }
    if (!S.empty()) valid = false;
    return (valid) ? (1) : (0);
}

void run(){
    /* code HERE */
    string s;
    while (1) {
        getline(cin, s);
        if (s == ".") break;
        int res = parse(s);
        cout << ((res==1) ? "yes\n": "no\n");
    }
    return;
}

int main(void){
    PRE_PROC
    run();
    return 0;
}