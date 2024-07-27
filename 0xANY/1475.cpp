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
    // 1. 각 자리수를 count
    // 2. 6, 9 값을 더한 값이 x라면, 6번째 배열에 x/2 + 1 값으로 대체
    // 3. 배열 cnt[i] 중에서 가장 큰 값 리턴

    int n, x, i, res;
    int cnt[10] = {0, };
    
    cin >> n;
    while (n > 0) {
        x = n % 10;
        cnt[x]++;
        n /= 10;
    }
    
    x = (cnt[6] + cnt[9] + 1) / 2;
    cnt[6] = x;

    res = -1;
    for (i=0; i<9; i++) {
        if (cnt[i] > res) res = cnt[i];
    }
    cout << res << '\n';
}
int main(void){
    PRE_PROC
    run();
    return 0;
}