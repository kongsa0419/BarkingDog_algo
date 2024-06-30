/**
 * name:    윷놀이
 * solved:  Y
 */

#include<iostream>
#include<string>
#include<algorithm>
#define PRE_PROC ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
using namespace std;

void run(){
    /* code HERE */
    int p, g;
    int iter{3};
    while(iter--) {
        p = 0; //등의 개수
        for(int i=0; i<4; i++){
            cin >> g;
            if(g) p++;
        }
        char stat[5] = {'D', 'C', 'B', 'A', 'E'};
        cout << stat[p] << '\n';
    }
}
int main(void){
    PRE_PROC
    run();
    return 0;
}