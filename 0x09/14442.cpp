/**
 * name:    
 * solved:  N
 * 
 * BFS
 * 부술수 있으면 부수는 경우 +1 (option)
 * 상하좌우 +4
 * 
 * 벽을 부수는 경우랑 부수지 않는 경우 모두 step 1개 짜리니까 (n-1,m-1)에 먼저 도달하는대로 출력 후 return
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
int n,m,z,i,j,k;
string map[LMT+2];
int dist[12][LMT+2][LMT+2];

inline bool oob(int y, int x) {
    return (x<0 || y<0 || y>=n || x>=m);
}

void pmap() {
    for(int i=0; i<n; i++){
        for(int j=0; j<m;j++){
            cout << map[i][j];
        }
        cout << endl;
    }
}
void dbg(){ 
    cout << "dist)\n";
    for(int k=0;k<=10;k++){
        cout << "[" << k << "]\n";
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout << dist[k][i][j] << ' ';
            }
            cout << endl;
        }
        cout << endl;
    }
}

int main(void){
    PRE_PROC
    cin >> n >> m >> z;
    for(i=0;i<n;i++){
        cin >> map[i];
        /*
        for(j=0;j<m;j++){
            fill(&dist[0][i][j], &dist[11][i][j], -1);
        }
        */
    }
    int step = -1;
    queue<tuple<int,int,int>> q;
    dist[0][0][0] = 1;
    q.push({0,0,0});
    while(!q.empty()) {
        int a,b,c; // caution! a = z축
        tie(a,b,c) = q.front(); q.pop();
        if(b==n-1 && c==m-1) {
            step = dist[a][b][c];
            break;
        }
        for(int d=0; d<4; d++) {
            int nz = a;
            int ny = b + dy[d];
            int nx = c + dx[d];
            if(oob(ny,nx)) continue;
            if(map[ny][nx]=='1') nz++;
            if(nz > z || dist[nz][ny][nx] > 0) continue;
            dist[nz][ny][nx] = dist[a][b][c] + 1;
            q.push({nz,ny,nx});
        }
    }

    cout << step << endl;
    return 0;
}