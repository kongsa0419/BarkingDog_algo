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
/**
 * 
 *  push_front X: 정수 X를 덱의 앞에 넣는다.
    push_back X: 정수 X를 덱의 뒤에 넣는다.
    pop_front: 덱의 가장 앞에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
    pop_back: 덱의 가장 뒤에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
    size: 덱에 들어있는 정수의 개수를 출력한다.
    empty: 덱이 비어있으면 1을, 아니면 0을 출력한다.
    front: 덱의 가장 앞에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
    back: 덱의 가장 뒤에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
 */
void run(){
    /* code HERE */
    int n, x;
    deque<int> dq;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        if (s == "push_front") {
            cin >> x;
            dq.push_front(x);
        } else if (s == "push_back") {
            cin >> x;
            dq.push_back(x);
        } else if (s == "pop_front") {
            cout << ( dq.empty() ? (-1) : dq.front() ) << '\n';
            if (!dq.empty()) dq.pop_front();
        } else if (s == "pop_back") {
            cout << ( dq.empty() ? (-1) : dq.back() ) << '\n';
            if (!dq.empty()) dq.pop_back();
        } else if (s == "size") {
            cout << dq.size() << '\n';
        } else if (s == "empty") {
            cout << (int) dq.empty() << '\n';
        } else if (s == "front") {
            cout << ( dq.empty() ? (-1) : dq.front() ) << '\n';
        } else if (s == "back") {
            cout << ( dq.empty() ? (-1) : dq.back() ) << '\n';
        } else {}
    }   
}
int main(void){
    PRE_PROC
    run();
    return 0;
}