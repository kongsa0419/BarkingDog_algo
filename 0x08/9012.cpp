/**
 * name:    
 * solved:  N
 * 
 * 조건 1: '(' 여는 괄호일 경우 stack에 무조건 push
 * 조건 2: ')' 닫는 괄호일 경우 stack.top()이 '(' 여야만 유효. stack.pop()으로 괄호 제거.
 *          반면, ") )" 처럼 될 경우는 무효. 앞서 '('을 pop으로 제거하기 때문에 성립 불가능
 * 조건 3: 문자열의 끝에 도달하였을때 stack에 남은 괄호가 있으면 괄호 쌍이 맞지 않으므로 무효.
 */

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<stack>
#define PRE_PROC ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
using namespace std;
void play() {
    string str;
    cin >> str;
    int i, n;
    stack<char> S;
    for(i=0; i<str.length(); i++){
        if (str[i] == '(') {
            S.push(str[i]);
        } else if (!S.empty() && S.top() == '(') {
                S.pop();
        } else {
            break;
        }
    }
    cout << ( (S.empty() && (i == str.length()) ) ? "YES\n" : "NO\n");
    return;
}
void run(){
    /* code HERE */
    int tc;
    cin >> tc;
    while (tc--) {
        play();
    }
    return;
}
int main(void){
    PRE_PROC
    run();
    return 0;
}