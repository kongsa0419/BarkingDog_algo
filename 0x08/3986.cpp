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

int validate (string& w) {
    stack<char> S;
    int i=0;
    while (i < w.length()) {
        if (S.empty()) S.push(w[i]);
        else if (S.top() == w[i]) {
            S.pop();
        } else {
            S.push(w[i]);
        }
        i++;
    }
    return ((S.empty()) ? (1) : (0)); 
}

void run(){
    /* code HERE */
    int n, res=0;
    string word;
    cin >> n;
    while (n--) {
        cin >> word;
        res += validate(word);
    }
    cout << res << '\n';
}
int main(void){
    PRE_PROC
    run();
    return 0;
}