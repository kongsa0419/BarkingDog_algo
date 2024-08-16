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

int map[102][102];
bool map2[102][102];
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
int n, i, j, k, x;
int vis[101]; //1 ~ 100 까지의 높이만큼 비가 오면 최대영역의 개수 기록
vector<int> v;

// 높이 h일때 map을 참조하여 물에 잠기지 않는 안전한 영역의 최대개수 return
int bfs (const int& h){
    for(i=0;i<n;i++) fill(map2[i], map2[i]+n, false); //init
    // paint
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if (map[i][j] <= h) {
                map2[i][j] = true;
            }
        }
    }
    int res = 0;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if (!map2[i][j]) {
                res++;
                queue<pair<int,int>> q;
                q.push({i,j});
                map2[i][j] = true;
                while(!q.empty()){
                    auto a = q.front(); q.pop();
                    for(k=0;k<4;k++){
                        int ny = a.X + dy[k];
                        int nx = a.Y + dx[k];
                        if (ny<0 || nx<0 || ny>=n || nx>=n) continue;
                        if (map2[ny][nx]) continue;
                        map2[ny][nx] = true;
                        q.push({ny,nx});
                    }
                }
            }
        }
    }
    return res;
}

void dbg() {
    fill(vis, vis+101, 0); //
    cout << "after fill(): " << vis[0] << '\n';
    for(i=1;i<=10;i++){
        for(j=1;j<=10;j++){
            cout << vis[10*(i-1)+j] << ' ';
        }
        cout << '\n';
    }
}
void input() {
    cin >> n;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cin >> map[i][j];
            if (vis[map[i][j]] == 0) {
                v.emplace_back(map[i][j]); // height 기록
                vis[map[i][j]] = 1;
            }
        }
    }
    v.emplace_back(0); // 물 높이가 0일 수도 있을듯
    int _max = -1;
    for (int a : v) {
        int tmp = bfs(a); // 높이 a일때 물에 안잠기는 최대 영역 개수
        vis[a] = tmp;     // record
        if (_max < tmp) _max = tmp;
    }
    cout << _max << '\n';
}
void run(){
    /* code HERE */
    input();    
}
int main(void){
    PRE_PROC
    run();
    return 0;
}