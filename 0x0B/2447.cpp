/**
 * name:    
 * solved:  N
 */

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<tuple>

#define PRE_PROC ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
using namespace std;

int d[3] = {0,1,2};
char map[2200][2200];
void func(const int& n, const int& y, const int& x) {
    if(n==1) {
        map[y][x] = '*';
        return;
    }

    int p = n/3;
    int i,j;
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            if(i==1 && i==j) {
                for(int ny=y+p; ny<y+2*p; ny++) {
                    for(int nx=x+p; nx<x+2*p; nx++){
                        map[ny][nx] = ' ';
                    }
                }
            } else {
                func(p, y+d[i]*p, x+d[j]*p);
            }
        }
    }

}
int main(void){
    PRE_PROC
    int n, i, j;
    cin >> n;
    func(n, 0, 0);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cout << map[i][j];
        }
        cout << '\n';
    }
    return 0;
}