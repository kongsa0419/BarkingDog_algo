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
#define PRE_PROC ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
using namespace std;
#define X first
#define Y second
#define LIMIT 2'147'000'000

int map[1005][1005];
int days[1005][1005];
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};
int n, m;
int ret = 0; // days
bool rotten;
void run(){
    /* code HERE */
    queue<pair<int,int>> Q;
    cin >> m >> n;
    int i,j, k;
    rotten = false;
    for (i=0; i<n; i++) {
        fill(days[i], days[i]+m+1, LIMIT);
        for (j=0; j<m; j++) {
            cin >> map[i][j];
            if (map[i][j] == 0) {
                days[i][j] = -1;
                rotten = true;
            } else if (map[i][j] == 1) {
                Q.push({i,j});
                days[i][j] = 0;
            }
        }
    }
    if (!rotten) {
        cout << 0 << endl;
        return;
    }
    while(!Q.empty()) {
        auto& a = Q.front(); Q.pop();
        for (k=0; k<4; k++) {
            int ny = a.X + dy[k];
            int nx = a.Y + dx[k];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if (days[ny][nx] == -1) {
                days[ny][nx] = days[a.X][a.Y] + 1;
                Q.push({ny,nx});
            }
        }
    }
    rotten = false;
    for (i=0; i<n; i++){ 
        for (j=0; j<m; j++) {
            if (days[i][j] == -1) {
                rotten = true;
                break;
            }
            if (map[i][j] == 0 &&
                days[i][j] > ret) {
                ret = days[i][j];
            }
        }
    }
    if (rotten) cout << -1;
    else cout << ret;
}

int main(void){
    PRE_PROC
    run();
    return 0;
}