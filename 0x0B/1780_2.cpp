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

// 
void verify(const vector<vector<int>>& map, int n, const int& y, const int& x, vector<int>& val) {
    bool same = true;
    int i,j,k1,k2;
    int cmp = map[y][x];
    for(i=y;i<y+n && same;i++){
        for(j=x;j<x+n && same;j++){
            if(map[i][j]!=cmp) same = false;
        }
    }
    if(n==1 || same) { // base condition
        switch(cmp){
            case -1: 
                val[0]++;  break;
            case 0:
                val[1]++;  break;
            case 1:
                val[2]++;  break;
        }
        return;
    }

    int d[3]={0,1,2};
    for(k1=0;k1<3;k1++){
        for(k2=0; k2<3; k2++){
            verify(map, n/3, y+(n/3)*d[k1], x+(n/3)*d[k2], val);
        }
    }
}

int main(void){
    PRE_PROC
    int n,i,j,k;
    vector<int> val(3);
    cin >> n;
    vector<vector<int>> map(n, vector<int>(n)); // 초기화 이렇게?
    for(i=0;i<n;i++) 
        for(j=0; j<n; j++)
            cin >> map[i][j];
    verify(map, n, 0, 0, val);
    for(i=0; i<3; i++){
        cout << val[i] << endl;
    } 
    return 0;
}