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

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
int n, i, j, k;
int vis[105][105];
string map1[105], map2[105];
void run(){
    /* code HERE */
    cin >> n;
    for (i=0; i<n; i++){
        cin >> map1[i];
        map2[i] = map1[i];
        for(j=0; j<n; j++){
            if(map2[i][j] == 'R') map2[i][j] = 'G'; // R을 G로 바꿔서 추론
        }
    }
    int x1=0, x2=0;
    // char arr[3] = {'R','G','B'};
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(!vis[i][j]) {
                queue<pair<int,int>> q;
                x1++;
                q.push({i,j});
                while(!q.empty()) {
                    auto& a = q.front(); q.pop();
                    vis[a.X][a.Y] = 1;
                    for(k=0; k<4; k++){ 
                        int ny = a.X + dy[k];
                        int nx = a.Y + dx[k];
                        if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
                        if(!vis[ny][nx] && map1[ny][nx] == map1[i][j]) {
                            q.push({ny,nx});
                            vis[ny][nx] = 1;
                        }
                    }
                }
            }
        }
    }

    for(i=0;i<n;i++) fill(vis[i], vis[i]+n, 0); //init
 
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(!vis[i][j]){
                queue<pair<int,int>> q;
                x2++;
                q.push({i,j});
                while(!q.empty()){
                    auto& a = q.front(); q.pop();
                    vis[a.X][a.Y] = 1;
                    for(k=0;k<4;k++){
                        int ny = a.X + dy[k];
                        int nx = a.Y + dx[k];
                        if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
                        if(!vis[ny][nx] && map2[ny][nx] == map2[i][j]) {
                            q.push({ny,nx});
                            vis[ny][nx] = 1;
                        }
                    }
                }
            }
        }
    }
    cout << x1 << ' ' << x2 << '\n';
}
int main(void){
    PRE_PROC
    run();
    return 0;
}