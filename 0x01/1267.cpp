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
    int n, x, i, k;
    int ys, ms;
    cin >> n;

    int arr [25];
    for(i=0; i<n; i++) {
        cin >> arr[i];
    }

    // 1. 영식
    x = 0; // sum
    for(i=0; i<n; i++) {
        k = (arr[i] / 30) + 1; // 기본 시간 (1)
        x += (k * 10);
    }
    ys = x;

    // 2. 민식
    x = 0;
    for(i=0; i<n; i++) {
        k = (arr[i] / 60) + 1;
        x += (k * 15);
    }
    ms = x;

    if (ys == ms) {
        cout << "Y M " << ms << '\n';
    } else {
        if (ys < ms) cout << "Y " << ys << '\n';
        else cout << "M " << ms << '\n';
    }
    return;
}

int main(void){
    PRE_PROC
    run();
    return 0;
}