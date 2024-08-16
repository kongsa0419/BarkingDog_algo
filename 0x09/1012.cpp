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

int map[55][55];
int vis[55][55];
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
int n, m,  i, j, k;
void init() {
    n = m = i = j = k = 0;
    for(i=0; i<55; i++){
        fill(map[i], map[i]+55, 0);
        fill(vis[i], vis[i]+55, 0);
    }
}
void play() {
    int cnt = 0;
    queue<pair<int,int>> Q;
    cin >> m >> n >> k;
    while (k--) {
        cin >> j >> i;
        map[i][j] = 1;
        Q.push({i,j});
    }
    while(!Q.empty()) {
        auto& a = Q.front(); Q.pop();
        if (!vis[a.X][a.Y]) {
            // bfs
            queue<pair<int,int>> area;
            area.push({a.X, a.Y});
            vis[a.X][a.Y] = 1;
            cnt++;
            while(!area.empty()) {
                auto& p = area.front(); area.pop();
                for(k=0; k<4; k++) {
                    int ny = p.X + dy[k];
                    int nx = p.Y + dx[k];
                    if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
                    if (vis[ny][nx] == 1 || map[ny][nx] == 0) continue;
                    area.push({ny, nx});
                    vis[ny][nx] = 1;
                }
            }
        }
    }
    cout << cnt << endl;
}
void run(){
    /* code HERE */
    int tc;
    cin >> tc;
    while(tc--) {
        init();
        play();
    }    
}
int main(void){
    PRE_PROC
    run();
    return 0;
}