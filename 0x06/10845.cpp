/**
 * name:    
 * solved:  N
 */

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#define PRE_PROC ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
using namespace std;
/**
 * 
 *  push X: 정수 X를 큐에 넣는 연산이다.
    pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
    size: 큐에 들어있는 정수의 개수를 출력한다.
    empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
    front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
    back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
 */
void run(){
    /* code HERE */
    int n, x;
    string s;
    queue<int> q;
    cin >> n;
    while(n--) {
        cin >> s;
        if (s == "push") {
            cin >> x;
            q.push(x);
        } else if (s == "pop") {
            if (q.empty()) {
                cout << "-1\n";
            } else {
                cout << q.front() << '\n';
                q.pop();
            }
        } else if (s == "size") {
            cout << q.size() << '\n';
        } else if (s == "empty") {
            cout << (int)q.empty() << '\n';
        } else if (s == "front") {
            cout << ( (q.empty()) ? (-1) : q.front() ) << '\n';
        } else if (s== "back") {
            cout << ( (q.empty()) ? (-1) : q.back() ) << '\n';
        } else { 
            /* do nothing */ 
        }
        // print_queue(q);
    }
    return;
}
int main(void){
    PRE_PROC
    run();
    return 0;
}