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
    int arr[100'005];
    bool check[1'000'005];
    int n, x, i, k, res;
    res = 0;

    cin >> n;
    for (i=0; i<n; i++) {
        cin >> arr[i];
    }
    cin >> x;

    for (i=0; i<n; i++) {
        k = x - arr[i];
        if (k <= 1'000'000 && k >= 0) {
            if (check[k]){
                res++;
            }
        }
        if (check[arr[i]] == 0) {
            check[arr[i]] = 1;   
        }
    }
    cout << res << '\n';
    return;
}
int main(void){
    PRE_PROC
    run();
    return 0;
}