/**
 * name:    
 * solved:  N
 * 차원이 바뀌는 경우 헷갈림
 * 그냥 기존대로 해도 x축 대칭한것처럼 생각하고 진행
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
int n, m, k, i, j, x;
bool map[102][102];
void input() {
    int x1, y1, x2, y2;
    cin >> n >> m >> x; // Width x Height
    while(x--) {
        cin >> x1 >> y1 >> x2 >> y2;
        // fill
        for (i=y1; i<y2; i++) {
            for(j=x1; j<x2; j++) {
                if (!map[i][j]) map[i][j] = true;
            }
        }
    }
}
void dbg() {
    cout << "dbg) (W,H):" << m << ',' << n << '\n';
    for(i=0;i<n;i++) {
        for(j=0;j<m;j++) {
            cout << ((map[i][j]) ? '*' : '_') << ' ';
        }
        cout << "|\n";
    }
}
void calc() {
    int island = 0;
    int size;
    vector<int> area;
    queue<pair<int,int>> q;
    for(i=0;i<n;i++) {
        for(j=0;j<m;j++){
            if (map[i][j] == false) {
                size = 0;
                map[i][j] = true;
                q.push({i,j});
                island++;
                while(!q.empty()) {
                    auto& a = q.front(); q.pop();
                    size++;
                    for(x=0; x<4; x++) {
                        int ny = a.X + dy[x];
                        int nx = a.Y + dx[x];
                        if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
                        if (map[ny][nx]) continue;
                        q.push({ny,nx});
                        map[ny][nx] = true;
                    }
                }
                area.emplace_back(size);
            }
        }
    }
    sort(area.begin(), area.end());
    cout << island << '\n';
    for (const auto a : area) {
        cout << a << ' ';
    }
}
void run(){
    /* code HERE */
    input();
    // dbg();
    calc();
}
int main(void){
    PRE_PROC
    run();
    return 0;
}