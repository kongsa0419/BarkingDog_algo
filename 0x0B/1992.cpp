/**
 * name:    
 * solved:  N
 * 예제만 봐서는 n==1일때 ()씌워야하는지 알수 없음.
 * 엄청 헤맸으니, 다시한번 풀어볼것
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
int dy[4] = {0,0,1,1};
int dx[4] = {0,1,0,1};

void func(const vector<string>& map, const int& y, const int& x, const int& n){
    if(n==1) {
        //BASE CONDITION
        cout << map[y][x];
        return;
    } 
    
    bool same = true;
    char cmp = map[y][x];
    int i,j;
    for(i=y; i<y+n && true; i++){
        for(j=x; j<x+n && true; j++){
            if(cmp != map[i][j]) same = false;
        }
    }
    if(same) cout << cmp;
    else {
        cout << '(';
        for(int k=0; k<4; k++){
            int ny = y + (n/2)*dy[k];
            int nx = x + (n/2)*dx[k];
            func(map, ny, nx, n/2);
        }
        cout << ')';
    }
}
int main(void){
    PRE_PROC
    int n, i, j;
    cin >> n;
    vector<string> map(n);
    for(i=0; i<n; i++) {
        cin >> map[i];
    }
    func(map, 0, 0, n);
    return 0;
}