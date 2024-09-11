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

#define X first
#define Y second
#define LMT 100
#define SIZE 102
#define PRE_PROC ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
using namespace std;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
bool map[SIZE][SIZE]; // light on(true)
bool vis[SIZE][SIZE]; // visit
int n, m;
deque<pair<int,int>> sw[SIZE][SIZE];

int count(){ //map에서 불 켜져있는 방의 수 구함
    int cnt=0;
    for(int i=1; i<=n; i++){
        for(int j=1;j<=n;j++){
            if(map[i][j]) cnt++;
        }
    }
    return cnt;
}
int main(void){
    PRE_PROC
    /* code HERE */
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        sw[a][b].push_back({c,d}); // 20'000번 I/O 연산
    }

    queue<pair<int,int>> q;
    q.push({1,1});
    map[1][1] = true;
    vis[1][1] = true;
    int nu = 1;
    while(!q.empty()) {
        int y,x,ny,nx;
        tie(y,x) = q.front(); q.pop();
        deque<pair<int,int>>& adj = sw[y][x];
        for(int i=0; i<adj.size(); i++) {
            tie(ny,nx) = adj[i]; // 스위치가 연결되어 불을 킬 수 있는 곳
            if(vis[ny][nx]) continue;
            map[ny][nx] = true; // 현재 위치에서 스위치로 켤 수 있는 모든 곳의 불을 켠다.
            for(int k=0; k<4; k++) {
                int ky = ny + dy[k];
                int kx = nx + dx[k];
                if(ky<1 || kx<1 || ky>n || kx>n) continue;
                if(!vis[ky][kx]) continue;
                vis[ny][nx] = true;
                q.push({ny,nx});
                break;
            }
        }
        for(int k=0; k<4; k++){
            int ky = y + dy[k]; // 현재 위치에서 내가 닿을 수 있는 곳
            int kx = x + dx[k];
            if(ky<1 || kx<1 || ky>n || kx>n) continue;
            if(vis[ky][kx] || !map[ky][kx]) continue;
            vis[ky][kx] = true;
            q.push({ky,kx});
        }
    }

    cout << count() << endl;
    return 0;
}