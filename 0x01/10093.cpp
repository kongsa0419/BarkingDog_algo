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
    long long a, b, tmp;
    cin >> a >> b;

    if (a > b) { // swap (make a < b)
        tmp = a;
        a = b;
        b = tmp; 
    } 

    if (b - a <= 1) {
        cout << 0; return;
    }
    cout << (b - a  - 1) << '\n';
    do {
        cout << ++a << ' ';
    } while (a < b-1);
    return;
}
int main(void){
    PRE_PROC
    run();
    return 0;
}