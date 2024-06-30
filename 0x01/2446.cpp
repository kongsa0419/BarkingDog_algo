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
    int n, i, j, x;
    cin >> n;

    i = 0;
    while (i < n) {
        // i 개 공백
        // 2 * (n - i) - 1개의 별
        x = i;
        while (x--) cout << ' ';
        x = 2 * (n - i) - 1;
        while (x--) cout << '*';
        cout << '\n';
        i++;
    }

    i = 1;
    while (++i <= n) {
        // n - i개 공백
        // 2 * i - 1개 별
        x = n - i;
        while (x--) cout << ' ';
        x = 2 * i - 1; 
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