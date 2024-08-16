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

int map[103][103][103];
int dy[6] = {0, 1, 0, -1, 0, 0};
int dx[6] = {1, 0, -1, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
queue<tuple<int,int,int>> q1, q2;
int day = 0;
int n, m, h, i, j, k, x;
void input() {
    cin >> m >> n >> h;
    for (k=0; k<h; k++) {
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                cin >> map[k][i][j];
                if (map[k][i][j] == 1) {
                    q1.push(make_tuple(k,i,j));
                } else if (map[k][i][j] == 0) {
                    q2.push(make_tuple(k,i,j));
                }
            }
        }
    }
}
void run(){
    /* code HERE */
    input();
    if (q2.empty()) {
        cout << 0 << '\n';
        return;
    }
    while (!q1.empty()) {
        tuple<int,int,int> t = q1.front(); q1.pop();
        if (day < map[get<0>(t)][get<1>(t)][get<2>(t)]) {
            day = map[get<0>(t)][get<1>(t)][get<2>(t)];
        }
        for(x=0; x<6; x++) {
            int nh = get<0>(t) + dz[x];
            int ny = get<1>(t) + dy[x];
            int nx = get<2>(t) + dx[x];
            if (nh < 0 || ny < 0 || nx < 0 ||
                nh >= k || ny >= n || nx >= m) continue;
            if (map[nh][ny][nx] == 0) {
                map[nh][ny][nx] = map[get<0>(t)][get<1>(t)][get<2>(t)] + 1;
                // day+1 해도 되는지 테스트해보고 싶네
                q1.push({nh,ny,nx}); //?
            }
        }
    }
    // 확인
    while (!q2.empty()) {
        tuple<int,int,int> t = q2.front(); q2.pop();
        if(map[get<0>(t)][get<1>(t)][get<2>(t)] == 0) {
            cout << -1 << '\n';
            return;
        }
    }
    cout << day - 1 << '\n';
}
int main(void){
    PRE_PROC
    run();
    return 0;
}