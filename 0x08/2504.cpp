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
#define X ch
#define Y mult
#define Z accum
using namespace std;

typedef struct data {
    char ch;
    int mult, accum;
}Data;

void run(){
    /* code HERE */
    string s;
    cin >> s;
    stack<Data> S; // parenthesis, multiply, accumlate
    int res = 0, valid = 1;
    int val = 0;
    for (int i=0; i<s.length(); i++) {
        if (s[i] == '(') {
            S.push({s[i], 2, 0});
        } else if (s[i] == '[') {
            S.push({s[i], 3, 0});
        } else {
            if (S.empty() || (s[i] == ')' && S.top().X == '[') || (s[i] == ']' && S.top().X == '(') ) {
                valid = 0;
                break;
            }
            if (S.top().Z == 0) val = S.top().Y;
            else val = S.top().Y * S.top().Z;
            S.pop();
            if (S.empty()) res += val;
            else S.top().Z += val;
        }
    }

    if (!valid) cout << 0 << endl;
    else cout << res << endl;
}
int main(void){
    PRE_PROC
    run();
    return 0;
}