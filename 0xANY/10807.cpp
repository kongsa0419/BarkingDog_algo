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
    int n, i, x;
    int cnt[205] = {0, }; // -100 ~ 100

    cin >> n;
    for (i=0; i<n; i++) {
        cin >> x;
        cnt[x + 100]++;
    }
    cin >> x;

    cout << cnt[x+100];
}
int main(void){
    PRE_PROC
    run();
    return 0;
}