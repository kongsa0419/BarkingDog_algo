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
    int i, j, n, x;
    cin >> n;
    i=0;
    while (++i <= n) {
        // i개의 별
        // 2 * (n-i) 개의 공백
        // i개의 별
        x = i;
        while(x--) cout << '*';
        x = 2*(n-i);
        while(x--) cout << ' ';
        x = i;
        while(x--) cout << '*';
        cout << '\n';
    }

    i = 0;
    while (++i < n) {
        // n-i개의 별
        // 2 * i 개의 공백
        // n-i개의 별
        x = n - i;
        while (x--) cout << '*';
        x = 2 * i;
        while (x--) cout << ' ';
        x = n - i;
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