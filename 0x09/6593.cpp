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

int dy[6] = {0, 1, 0, -1, 0, 0};
int dx[6] = {1, 0, -1, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
int n, m, z, i, j, k;
int sx, sy, sz, gx, gy, gz;
bool map[32][32][32]; // pass or no
queue<tuple<int,int,int,int>> q;

void init() {
    while(!q.empty()) q.pop();
    for(k=0;k<z;k++)
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                map[k][i][j] = false;
}
void input() {
    char ch;
    for(k=0;k<z;k++){
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                cin >> ch;
                if (ch != '#') {
                    map[k][i][j] = true;
                }
                if (ch == 'S') {
                    sz = k; sy = i; sx = j;
                    q.push({sz,sy,sx,0});
                } else if (ch == 'E'){
                    gz = k; gy = i; gx = j;
                }
            }
        }
        cin.ignore(); // 빈 칸 날림
    }
}
void game() {
    int step = -1; // flag
    while(!q.empty() && step == -1) {
        auto a = q.front(); q.pop(); //tuple
        sz = get<0>(a);
        sy = get<1>(a);
        sx = get<2>(a);
        if (sz == gz && sy == gy && sx == gx) {
            step = get<3>(a);
            break;
        }
        for(k=0; k<6; k++) {
            int nz = sz + dz[k];
            int ny = sy + dy[k];
            int nx = sx + dx[k];
            if (nz<0 || ny<0 || nx<0 || nz>=z || ny>=n || nx>=m) continue;
            if (!map[nz][ny][nx]) continue;
            q.push({nz,ny,nx, get<3>(a) + 1});
            map[nz][ny][nx] = false; // visit
        }
    }
    if(step != -1) {
        cout << "Escaped in " << step << " minute(s). \n";
    } else {
        cout << "Trapped!\n";
    }
}

void run(){
    /* code HERE */
    while(1) {
        cin >> z >> n >> m; // 층, 행, 열
        if (z == 0 && n== 0 && m == 0) return;
        init();
        input();
        game();
    }
    
}
int main(void){
    PRE_PROC
    run();
    return 0;
}