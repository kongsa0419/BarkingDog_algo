#include<iostream>
#include<cstring> // memcpy
#include<queue>
#include<algorithm> // max
using namespace std;
#define PRE_PROC ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
#define X first
#define Y second

int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};

int n,m,i,j,k;
int map[302][302];
int year;
int count() {
    int cnt = 0; // 섬의 개수
    bool vis[302][302] = {{false,},};
    for(i=1; i<n-1; i++) {
        for(j=1; j<m-1; j++){
            if (map[i][j] == 0 || vis[i][j]) continue;
            cnt++;
            queue<pair<int,int>> q;
            q.push({i,j});
            vis[i][j] = true;
            while(!q.empty()) {
                auto a = q.front(); q.pop();
                for(k=0;k<4;k++){
                    int ny = a.X + dy[k];
                    int nx = a.Y + dx[k];
                    if(map[ny][nx] > 0 && !vis[ny][nx]) {
                        vis[ny][nx] = true;
                        q.push({ny,nx});
                    }
                }
            }
        }
    }
    return cnt;
}
void melt() {
    int sea[302][302] = {{0,},};
    int cnt;
    for(i=1;i<n-1;i++){
        for(j=1;j<m-1;j++){
            if(map[i][j] == 0) continue;
            cnt = 0; // 사방의 바다 개수
            for(k=0;k<4;k++){
                int ny = i + dy[k];
                int nx = j + dx[k];
                if(map[ny][nx] == 0) cnt++;
            }
            sea[i][j] = cnt;
        }
    }
    for(i=1;i<n-1;i++){
        for(j=1;j<m-1;j++){
            if(map[i][j] == 0) continue;
            map[i][j] = max(0, map[i][j] - sea[i][j]);
        }
    }
}

int main(void) {
    PRE_PROC
    cin >> n >> m;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cin >> map[i][j];
        }
    }
    year=0;
    while(1) {
        int cnt = count(); // 섬의 개수
        if (cnt == 0) {
            cout << 0 << '\n';
            break;
        } else if(cnt > 1) {
            cout << year << '\n';
            break;
        }
        melt();
        year++;
    }
    return 0;
}