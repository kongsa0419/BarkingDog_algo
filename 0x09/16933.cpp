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
#define LMT 1000

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

string map[LMT+2];
int dist[LMT+2][LMT+2][12][2]; // y,x,k, night
int n,m,z,i; // j,k;
int night; //처음엔 day로 시작
queue<tuple<int,int,int,int>> q; // y,x,벽뚫횟수,night

void dbg(){
    for(int k=0; k<=z; k++){
        cout << "[map:" << k << "]\n";
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cout << dist[i][j][k][0] << ',' << dist[i][j][k][1];
            }
            cout << endl;
        }
    }
}
//NOTE: stay는 벽에 막혀있고 밤일때에만 함. (낮에 stay해봤자 달라질게 없음)
int main(void){
    PRE_PROC
    cin >> n >> m >> z;
    for(i=0; i<n; i++){
        cin >> map[i];
    }
    night = 0; // false
    
    int step = -1;
    q.push({0,0,0,0});
    dist[0][0][0][0] = 1;
    while(!q.empty()){
        int a,b,c,d;
        tie(a,b,c,d) = q.front(); q.pop();
        if(a==n-1 && b==m-1) {
            step = dist[a][b][c][d];
            break;
        }
        for(int dir=0; dir<4; dir++){
            int ny = a + dy[dir];
            int nx = b + dx[dir];
            int nd = ( (d>0)? 0 : 1 );
            if(ny<0 || nx<0 || ny>=n || nx>=m) continue;
            if(map[ny][nx]=='0'){
                if(dist[ny][nx][c][nd]) continue;
                dist[ny][nx][c][nd] = dist[a][b][c][d]+1;
                q.push({ny,nx,c,nd});
            } else {
                if(c+1 > z || d) {
                    // no more wall-break (just stay)
                    if(dist[a][b][c][nd]) continue;
                    dist[a][b][c][nd] = dist[a][b][c][d] + 1;
                    q.push({a, b, c, nd});
                }else {
                    // available of wall-breaking
                    if(dist[ny][nx][c+1][nd]) continue;
                    dist[ny][nx][c+1][nd] = dist[a][b][c][d] + 1;
                    q.push({ny,nx,c+1,nd});
                }
            }
        }
    }
    
    cout << step << '\n';
    return 0;
}