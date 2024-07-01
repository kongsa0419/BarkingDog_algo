/**
 * name:    
 * solved:  N
 */

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#define PRE_PROC ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
using namespace std;

void run(){
    /* code HERE */
    int n, x, i, sp, ep, res;
    int arr[100'005];
    res = 0;

    cin >> n;
    for (i=0; i<n; i++) {
        cin >> arr[i];
    }
    cin >> x;

    sort(arr, arr+n);

    sp = 0;
    ep = n-1;
    do {
       if (arr[sp] + arr[ep] > x) {
            ep--;
       } else if (arr[sp] + arr[ep] < x) {
            sp++;
       } else { 
            sp++;
            ep--;
            res++;
       }
    } while(sp < ep);

    cout << res << '\n';
    return;
}
int main(void){
    PRE_PROC
    run();
    return 0;
}