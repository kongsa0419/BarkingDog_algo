/**
 * name:    
 * solved:  N
 * 스택: 삽입, 삭제, 조회 모두 O(1)
 */

#include<iostream>
#include<string>
#include<stack>
#include<algorithm>
#define PRE_PROC ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
using namespace std;

void run(){
    /* code HERE */
    int n, x;
    string cmd;
    stack<int> s;

    cin >> n;
    while (n--) {
        cin >> cmd;
        if (cmd == "push") {
            cin >> x;
            s.push(x);
        } else if (cmd == "pop") {
            if (s.empty()) {
                cout << "-1\n";
            } else {
                cout << s.top() << '\n';
                s.pop();
            }
        } else if (cmd == "size") {
            cout << s.size() << '\n';
        } else if (cmd == "empty") {
            cout << int(s.empty()) << '\n';
        } else if (cmd == "top") {
            if (s.empty()) {
                cout << -1 << '\n';
            } else {
                cout << s.top() << '\n';
            }
        }
    }
}

int main(void){
    PRE_PROC
    run();
    return 0;
}

/*
push X: 정수 X를 스택에 넣는 연산이다.
pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 스택에 들어있는 정수의 개수를 출력한다.
empty: 스택이 비어있으면 1, 아니면 0을 출력한다.
top: 스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
*/