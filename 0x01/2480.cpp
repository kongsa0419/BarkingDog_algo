/**
 * name:    주사위 세개
 * solved:  N
 */

#include<iostream>
#include<string>
#include<algorithm>
#define PRE_PROC ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
using namespace std;

void run(){
    /* code HERE */
    int dice[3], i;
    for(i=0; i<3; i++) cin >> dice[i];
    sort(dice, dice+3);
    
    int stat = -1;
    if(dice[0] == dice[1] && dice[1]== dice[2]) stat = 1;
    else if (dice[0] == dice[1] || dice[1] == dice[2]) stat = 2;
    else stat = 3;

    switch (stat) 
    {
        case 1: cout << 1e4 + dice[0] * 1e3; break;
        case 2: 
        {
            if (dice[0] == dice[1])
                cout << 1e3 + dice[0] * 1e2;
            else 
                cout << 1e3 + dice[2] * 1e2;
            
            break;
        }
        case 3: cout << dice[2] * 100;
        break;
    }
    return;
}
int main(void){
    PRE_PROC
    run();
    return 0;
}