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
    int a,b,c;
    int x, j;
    vector<int> v(10, 0); // 0 ~ 9
    cin >> a >> b >> c;

    x = a * b * c;
    while (x > 0) {
       j = x % 10;
       v[j]++;
       x /= 10; 
    }

    for (j=0; j<10; j++) cout << v[j] << '\n';
    return;
}
int main(void){
    PRE_PROC
    run();
    return 0;
}