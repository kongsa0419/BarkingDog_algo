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

int dy[4]={0,0,1,1};
int dx[4]={0,1,0,1};
void func(const vector<string>& map, const int& n, const int& y, const int& x){
    int i,j,k;
    bool same = true;
    k = map[y][x];
    for(i=y;i<y+n && same;i++){
        for(j=x;j<x+n && same;j++){
            if(k!=map[i][j]) same = false;
        }
    }
    if(same || n==1) { // BASE CONDITION
        cout << map[y][x];
        return;
    }
    //compress
    cout << '(';
    for(i=0;i<4;i++){
        func(map, n/2, y+dy[i]*(n/2), x+dx[i]*(n/2));
    }
    cout << ')';
}
int main(void){
    PRE_PROC
    int n,i,j,k;
    cin >> n;
    vector<string> map(n);
    for(i=0;i<n;i++) cin >> map[i];
    func(map, n, 0,0);
    return 0;
}