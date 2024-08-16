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

string map[1005];
int dist1[1005][1005]; // fire
int dist2[1005][1005]; // jihoon
queue<pair<int,int>> Q1, Q2; // fire, jihhon
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

int n, m, i, j, k;
int ret = 0;

void disp() {
    cout << "-----------\n";
    puts("[fire]");
    for(i=0;i<n;i++) {
        for(j=0;j<m;j++){
            cout << dist1[i][j] << ' ';
        }
        cout << '\n';
    }
    puts("[jihoon]");
    for(i=0;i<n;i++) {
        for(j=0;j<m;j++){
            cout << dist2[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << "-----------\n";
}

void run(){
    /* code HERE */
    cin >> n >> m;
    for(i=0;i<n;i++){
        cin >> map[i];
        fill(dist1[i], dist1[i]+m, -1);
        fill(dist2[i], dist2[i]+m, -1);
        for(j=0;j<m;j++){
            if(map[i][j] == 'F') {
                Q1.push({i,j});
                dist1[i][j] = 0;
            }
            else if(map[i][j]=='J') {
                Q2.push({i,j});
                dist2[i][j] = 0;
            }
        }
    }

    while(!Q1.empty()) {
        auto& a = Q1.front(); Q1.pop();
        for(k=0; k<4; k++) {
            int ny = a.X + dy[k];
            int nx = a.Y + dx[k];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if (map[ny][nx] != '#' && dist1[ny][nx] == -1) {
                dist1[ny][nx] = dist1[a.X][a.Y] + 1;
                Q1.push({ny, nx});
            }
        }
    }
    int tmp1,tmp2;
    tmp1=tmp2=0;
    while(!Q2.empty()) {
        auto& a = Q2.front(); Q2.pop();
        for(k=0; k<4; k++) {
            int ny = a.X + dy[k];
            int nx = a.Y + dx[k];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m) {
                cout << (dist2[a.X][a.Y] + 1) << '\n';
                disp();
                return;
            }
            if (map[ny][nx] == '#' || dist2[ny][nx] != -1) continue;
            if (dist1[ny][nx] != -1 && dist2[a.X][a.Y]+1 >= dist1[ny][nx]) continue;
            dist2[ny][nx] = dist2[a.X][a.Y] + 1;
            Q2.push({ny, nx});
        }
    }
    
    cout << "IMPOSSIBLE\n";
    return;
}

int main(void){
    PRE_PROC
    run();
    return 0;
}