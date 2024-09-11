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

int dy[4] = {0,0,1,1};
int dx[4] = {0,1,0,1};
void func(const vector<vector<int>>& map, const int& n, const int& y, const int& x, vector<int>& cnt)
{
    bool same = true;
    int i,j,k;
    k = map[y][x];
    for(i=y; i<y+n&&same; i++){
        for(j=x; j<x+n&&same; j++) {
            if(map[i][j]!=k) same = false;
        }
    }
    if(same || n==1) { // BASE CONDITION
        cnt[k]++;
        return;
    }
    int hf = n/2;
    for(k=0; k<4; k++){
        func(map, hf, y+hf*dy[k], x+hf*dx[k], cnt);
    }
}
int main(void){
    PRE_PROC
    int n,i,j,k;
    cin >> n;
    vector<int> cnt(2, 0); //[WHITE, BLUE]
    vector<vector<int>> map(n);
    for(i=0;i<n;i++){
        map[i].reserve(n);
        for(j=0;j<n;j++){
            cin >> map[i][j];
        }
    }
    func(map, n, 0,0, cnt);
    cout << cnt[0] << '\n' << cnt[1] << '\n';
    return 0;
}