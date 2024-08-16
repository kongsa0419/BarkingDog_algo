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
#define X first
#define Y second
#define SIZE_ 100
#define LIMIT = 2'147'000'000;
#define PRE_PROC ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
using namespace std;

typedef struct data {
    int y,x,z;
}Data;
int map [SIZE_+5][SIZE_+5];
int vis [SIZE_+5][SIZE_+5];
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};

void run(){
    /* code HERE */
    int n, m, x, i, j;
    char ch;
    cin >> n >> m;
    for (i=1; i<= n; i++) {
        cin.ignore();
        for (j=1; j<=m; j++) {
            cin.get(ch);
            map[i][j] = ch - '0';
        }
    }
    int res = 0;
    queue<Data> Q;
    Q.push({1,1,1});
    vis[1][1] = 1;
    while (!Q.empty()) {
        Data d = Q.front(); Q.pop();
        if (d.y == n && d.x == m) {
            res = d.z;
            break;
        }
        // vis[d.y][d.x] = 1;
        // if (len[d.y][d.x] > d.z) len[d.y][d.x] = d.z;      
        for (int k=0; k<4; k++) {
            int ny = d.y + dy[k];
            int nx = d.x + dx[k];
            // 1. range check
            if (ny < 1 ||  nx < 1 || ny > n || nx > m) continue;
            // 2. map & visit check
            if (!map[ny][nx] || vis[ny][nx]) continue;
            Q.push({ny,nx,d.z+1}); //
            vis[ny][nx] = 1;
        }
    }
    cout << res << endl;
}
int main(void){
    PRE_PROC
    run();
    return 0;
}