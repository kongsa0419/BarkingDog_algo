#include <bits/stdc++.h>
using namespace std;
#define LMT 3*(1<<10)+2

char board[LMT][2*LMT-1];

void recur(int n, int y, int x){
    if(n==3) {
        // set
        board[y][x]='*';
        board[y+1][x-1] = board[y+1][x+1] = '*';
        for(int k=x-2; k<=x+2; k++) board[y+2][k] = '*';
        return;
    }
    int hf = n/2;
    recur(n/2, y, x);
    recur(n/2, y+hf, x-hf);
    recur(n/2, y+hf, x+hf);
}

int main(void){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        fill(board[i], board[i]+(2*n - 1), ' ');
    }
 
    recur(n, 0, n-1);

    //printboard
    int i,j;
    for(i=0; i<n; i++){
        for(j=0; j<2*n-1; j++){
            cout << board[i][j];
        }
        cout << '\n';
    }
    return 0;
}