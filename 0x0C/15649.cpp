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

void func(const int& n, const int& m, const int& sel, int map[], bool vis[]){
    int i;
    if(m<=sel) {
        // print
        for(i=0; i<m; i++){
            cout << map[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(i=1; i<=n; i++){
        if(vis[i]) continue;
        map[sel] = i;
        vis[i]=true;
        func(n,m, sel+1, map, vis);
        map[sel] = 0;
        vis[i]=false;
    }
}

int main(void){
    PRE_PROC
    int n,m;
    cin >> n >> m;
    
    int s=n+2;
    int map[s]={0,};
    bool vis[s] = {false,};

    func(n, m, 0, map, vis);
    return 0;
}