#include<iostream>
#include<string>
#include<algorithm>
#define PRE_PROC ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
using namespace std;

void run(){
    /* code HERE */
    int n, x, i;
    cin >> n;
    for(i=0; i<n; i++) {
        // i 개의 공백을 출력한 뒤
        x = i;
        while (x--) {
            cout << ' ';
        }
        // n - i개 별을 찍는다
        x = n - i;
        while (x--) {
            cout << '*';
        }
        cout << '\n';
    }
}
int main(void){
    PRE_PROC
    run();
    return 0;
}