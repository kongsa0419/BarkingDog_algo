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
#define PRE_PROC ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
using namespace std;


string map[105];
int dist [105][105];
int n, m;
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};

void run(){
    /* code HERE */
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        cin >> map[i];
        fill(&dist[i][1], &dist[i][m+1], -1);
    }
    queue<pair<int,int>> Q;
    Q.push({1,1});
    dist[1][1] = 1;
    while(!Q.empty()) {
        auto& a = Q.front(); Q.pop();
        // cout << '(' << a.X << ',' << a.Y << ')' << endl;
        if (a.X == n && a.Y == m) break;
        for (int i=0; i<4; i++) {
            int ny = a.X + dy[i];
            int nx = a.Y + dx[i];
            //1. range check
            if (ny < 1 || nx < 1 || ny > n || nx > m) continue;
            //2. map & visit check
            if (map[ny][nx-1] == '0' || dist[ny][nx] != -1) continue;
            Q.push({ny,nx});
            dist[ny][nx] = dist[a.X][a.Y] + 1;
        }
    }
    cout << dist[n][m] << endl;
}
int main(void){
    PRE_PROC
    run();
    return 0;
}