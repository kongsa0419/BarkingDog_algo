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

#define LIMIT 100'000'000

void run(){
    /* code HERE */
    int n, i, h;
    cin >> n;
    stack<pair<int, int>> s;
    
    s.push({LIMIT + 1, 0});
    for (i=1; i<=n; i++) {
        cin >> h;
        while (!s.empty() && s.top().first < h) {
            s.pop();
        }
        cout << s.top().second << ' ';
        s.push({h, i});
    }
    cout << '\n';
    return;
}
int main(void){
    PRE_PROC
    run();
    return 0;
}