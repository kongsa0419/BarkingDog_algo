#include<iostream>
#include<string>
#include<algorithm>
#define PRE_PROC ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
using namespace std;

void run(){
    /* code HERE */
    int n, i, j, x;
    cin >> n;
    
    j = n;
    while (j > 0) {
        x = n - j;
        while (x--) {
            cout << ' ';
        }
        
        x = 2*j - 1;
        while (x--) {
            cout << '*';
        }
        cout << '\n';
        --j;
    }
}
int main(void){
    PRE_PROC
    run();
    return 0;
}