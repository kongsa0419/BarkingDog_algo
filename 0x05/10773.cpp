/**
 * name:    
 * solved:  N
 */

#include<iostream>
#include<string>
#include<stack>
#include<algorithm>
#define PRE_PROC ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
using namespace std;

void run(){
    /* code HERE */
    int k, x;
    unsigned long long sum = 0;
    stack<int> s;

    cin >> k;
    while (k--) {
        cin >> x;
        if (x == 0) {
            if (!s.empty()) {
                s.pop();
            }
            continue;
        }
        s.push(x);
    }

    while (!s.empty()) {
        sum += s.top();
        s.pop();
    }
    cout << sum << '\n';
    return;
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