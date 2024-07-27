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
    int n, k, sex, grade, res;
    int check[2][6] = {{0, }, };
    res = 0;

    cin >> n >> k;
    for (int i=0; i<n; i++) {
        cin >> sex >> grade;
        check[sex][grade-1]++;
    }

    for (int *p = &check[0][0]; p < &check[0][0] + 12; p++) {
        if (*p > 0) {
            res += ((*p - 1) / k + 1);
        }
    }
    cout << res << '\n';
}
int main(void){
    PRE_PROC
    run();
    return 0;
}