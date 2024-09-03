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

int dy[4] = {0, 1, 0, -1}; // 일반 스텝
int dx[4] = {1, 0, -1, 0};
int ndy[8] = {-2,-1,1,2,2,1,-1,-2}; // 말 스텝
int ndx[8] = {1,2,2,1,-1,-2,-2,-1};

int map[202][202];
int dist[202][202][32]; // input()에서 -1로 초기화
int n,m,k,i,j;
void input() {
    cin >> k;
    cin >> m >> n;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cin >> map[i][j];
            fill(dist[i][j], dist[i][j]+32, -1);
        }
    }

}
inline bool OOB(int y, int x) {return (y<0 || x<0 || y>=n || x>=m);}
inline bool obstacle(int y, int x) {return (map[y][x] == 1);}

int main(void){
    PRE_PROC // 전처리
    input();
    bool found = false;
    int result = 0;
    queue<tuple<int,int,int,int>> Q; // {y, x, 일반step, 말step}
    Q.push({0,0,0,0});
    dist[0][0][0] = 0;
    while(!Q.empty() && !found) {
        auto a = Q.front(); Q.pop();
        int y, x, ns, hs;
        tie(y,x,ns,hs) = a;
        /* 아래 escape 조건이 있으면 안되나요? */
        if(y==n-1 && x==m-1) {
            found = true;
            result = ns + hs;
            break;
        }
        //1. 일반 step에 대한 처리
        for(int d=0; d<4; d++){
            int ny = y + dy[d];
            int nx = x + dx[d];
            // range check & 장애물 체크 & visit 체크
            if(OOB(ny, nx) || obstacle(ny, nx)) continue;
            if(dist[ny][nx][hs] != -1) continue;
            dist[ny][nx][hs] = dist[y][x][hs] + 1;
            Q.push({ny,nx,ns+1,hs});
        }

        //2. 말 step에 대한 처리
        if(hs >= k) continue; // horse step >= k 넘어서는지 확인
        for(int d=0; d<8; d++){
            int ny = y + ndy[d];
            int nx = x + ndx[d];
            // range check & 장애물 체크 & visit 체크
            if(OOB(ny, nx) || obstacle(ny, nx)) continue;
            if(dist[ny][nx][hs+1] != -1) continue;
            dist[ny][nx][hs+1] = dist[y][x][hs] + 1;
            Q.push({ny,nx,ns,hs+1});
        }
    }

    if(found) cout << result << endl;
    else cout << -1 << endl;
}