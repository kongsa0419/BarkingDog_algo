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

void run(){
    /* code HERE */
    int i, n;
    cin >> n;

    queue<int> q;
    i = 1;
    while (i <= n) {
        q.push(i++);
    }

    i = 0;
    while (q.size() != 1) {
        if (i == 1) {
            q.push(q.front());
            q.pop();
            i--;
        } else {
            i = 1;
            q.pop();
        }
    }
    cout << q.front() << '\n';
    return ;
}
int main(void){
    PRE_PROC
    run();
    return 0;
}