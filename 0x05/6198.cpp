/**
 * name:    
 * solved:  N
 */

#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<algorithm>
#define PRE_PROC ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
#define X first
#define Y second
#define LIMIT 1'000'000'000
using namespace std;
const int INF = 0x3f3f3f3f;

void run(){
    /* code HERE */
    int n, i, h, cnt;
    unsigned int sum = 0;
    cin >> n;
    stack<int> s;
    for (i=0; i<n; i++) {
        cin >> h;   
        while (!s.empty() && s.top() <= h) {
            s.pop();
        }
        sum += s.size();
        s.push(h);
    }
    cout << sum << '\n';
    return ;
}
int main(void){
    PRE_PROC
    run();
    return 0;
}