/**
 * name:    
 * solved:  N
 */

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#define PRE_PROC ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
#define X first
#define Y second
#define SIZE 500
using namespace std;

int map [SIZE+5][SIZE+5];
int vis [SIZE+5][SIZE+5];
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

void run(){
    /* code HERE */
    int n, m;
    int pics=0, res=0;
    int psize;
    queue<pair<int, int>> Q;
    cin >> n >> m;
    // input
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> map[i][j];
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (map[i][j] == 1 && vis[i][j] == 0) {
                // BFS
                psize = 0;
                pics++;
                Q.push({i,j});
                vis[i][j] = 1;
                while (!Q.empty()) {
                    pair<int,int> e = Q.front(); Q.pop();
                    psize++;
                    for (int d=0; d<4; d++){
                        int ny = e.X + dy[d];
                        int nx = e.Y + dx[d];
                        // 1. range check
                        if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
                        // 2. visit check
                        if (map[ny][nx] == 0 || vis[ny][nx]) continue;
                        Q.push({ny, nx});
                        vis[ny][nx] = 1;
                    }
                }
                if (psize > res) res = psize;
            }
        }
    }
    cout << pics << endl << res << endl;
}
int main(void){
    PRE_PROC
    run();
    return 0;
}