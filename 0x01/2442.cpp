#include<iostream>
#include<string>
#include<algorithm>
#define PRE_PROC ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
using namespace std;

void run(){
    /* code HERE */
    int n, i, j, x;
    cin >> n;

    // 각 줄에서 1, 3, 5, ... , 2N-1 개를 출력해야함 
    j = 0;
    while (++j <= n) {
        // n - j 개 공백 출력 후
        x = n - j; 
        while (x--) {
            cout << ' ';
        }
        // 2j - 1 개 별 출력
        x = 2 * j - 1;
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