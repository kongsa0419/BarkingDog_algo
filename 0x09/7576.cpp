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

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
int map[1005][1005];
queue<pair<int,int>> q1, q2;
int n, m, i, j, k;
int day = 0;
void run(){
    /* code HERE */
    cin >> m >> n;
    for(i=0; i<n; i++) {
        for (j=0; j<m; j++) {
            cin >> map[i][j];
            if (map[i][j] == 1) {
                q1.push({i,j});
            }else if (map[i][j] == 0) {
                q2.push({i,j});
            }
        }   
    }
    if (q2.empty()) {
        cout << 0 << endl;
        return;
    }
    while (!q1.empty()) {
        auto& a = q1.front(); q1.pop();
        if (day < map[a.X][a.Y]) day = map[a.X][a.Y];
        for(k=0; k<4; k++) {
            int ny = a.X + dy[k];
            int nx = a.Y + dx[k];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if (map[ny][nx] == 0) {
                q1.push({ny,nx});
                map[ny][nx] = day + 1;
            }
        }
    }
    while(!q2.empty()) {
        auto& a= q2.front(); q2.pop();
        if (map[a.X][a.Y] == 0) {
            cout << -1 << endl;
            return;
        }
    }
    cout << (day - 1) << endl;
}
int main(void){
    PRE_PROC
    run();
    return 0;
}