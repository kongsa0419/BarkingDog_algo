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

int dy[8] = {-2,-1,1,2,2,1,-1,-2};
int dx[8] = {1,2,2,1,-1,-2,-2,-1};
int map[305][305];
int tc, n, i, j, k;
void init() {
    n = i = j = k = 0;
    for(i=0; i<305; i++) {
        fill(map[i], map[i]+305, 0);
    }
}
void dbg(){
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
}
void play() {
    int day = 1;
    cin >> n;
    cin >> i >> j;
    map[i][j] = 1;  // knight
    queue<pair<int,int>> q;
    q.push({i,j});
    cin >> i >> j;
    map[i][j] = -1; //goal

    while(!q.empty()) {
        const auto& a = q.front(); q.pop();
        if (day < map[a.X][a.Y]) day = map[a.X][a.Y];
        if (a.X == i && a.Y == j) {
            cout << (day-1) << '\n';
            return;
        }
        for(k=0; k<8; k++) {
            int ny = a.X + dy[k];
            int nx = a.Y + dx[k];
            if (ny<0 || nx<0 || ny>=n || nx>=n) continue;
            if (map[ny][nx] <= 0) {
                map[ny][nx] = map[a.X][a.Y] + 1;
                q.push({ny,nx});
            }
        }
    }
}
void run(){
    /* code HERE */
    cin >> tc;
    while(tc--){
        init();
        play();
    }
}
int main(void){
    PRE_PROC
    run();
    return 0;
}