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
#define PRE_PROC ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
using namespace std;
#define OPEN 0
#define CLSE 1

int map[1002][1002];
int dist[1002][1002][2];
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
int n, m, i, j, k;
void run(){
    cin >> n >> m;
    for(i=0;i<n;i++){
        string line;
        cin >> line;
        for(j=0;j<m;j++){
            map[i][j] = line[j]-'0';
            // dist[i][j][0] = dist[i][j][1] = -1; // ??!?!??
        }
    }
    int res = -1; //flag
    queue<tuple<int,int,int>> q; // y, x, chance(0/1)
    q.push({0,0,0}); dist[0][0][0] = 1;
    q.push({0,0,1}); dist[0][0][1] = 1;
    while(!q.empty()) {
        int a,b,c,d;
        tie(a,b,c) = q.front(); q.pop();
        if (a==n-1 && b==m-1) {
            res = dist[a][b][c];
            break;
        }
        d = dist[a][b][c];
        for(k=0; k<4; k++) {
            int ny = a + dy[k];
            int nx = b + dx[k];
            if (ny<0 || nx<0 || ny>=n || nx>=m) continue;
            if (map[ny][nx] == CLSE) {
                if(c>0 && dist[ny][nx][c] == 0) {
                    dist[ny][nx][c-1] = d + 1;
                    q.push({ny,nx,c-1});
                }
            }// 벽을 부순 경우

            if(map[ny][nx] == OPEN && dist[ny][nx][c] == 0) {
                dist[ny][nx][c] = d + 1;
                q.push({ny, nx, c});
            } // 벽을 부수지 않은 경우
        }
    } 
    cout << res << endl;
}
int main(void){
    PRE_PROC
    run();
    return 0;
}