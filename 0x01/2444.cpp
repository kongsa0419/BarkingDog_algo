/**
 * name:    
 * solved:  N
 */

#include<iostream>
#include<string>
#include<algorithm>
#define PRE_PROC ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
using namespace std;

void run(){
    /* code HERE */
    int n, i, j, x, limit;
    cin >> n;

    limit = n;
    i = 0;
    while (++i <= limit) {
        // phase 1
        // n - line 개의 공백 출력
        // 2 * line - 1개의 별 출력
        x = n - i;
        while (x--) { 
            cout << ' ';
        }
        x = 2 * i - 1;
        while (x--) { 
            cout << '*';
        }
        cout << '\n';
    }

    i = 0;
    while (++i < limit) {
        // phase 2
        // i개의 공백 출력
        // 2 * (n - i) - 1개의 별 출력
        x = i;
        while (x--) cout << ' ';
        x = 2 * (n-i) - 1;
        while (x--) cout << '*';
        cout << '\n';
    }
    return;
}
int main(void){
    PRE_PROC
    run();
    return 0;
}