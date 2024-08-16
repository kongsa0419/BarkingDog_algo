/**
 * name:    
 * solved:  N
 * Brute Force 라서 막연히 시간 초과에 걸릴것 같은 두려움보단, 일단 시간복잡도를 구해보고 도전해보자.
 * 중첩반복문에서는 if() continue;로 depth를 줄이자
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
#define LIM 9999999
using namespace std;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
int n, x, i, j, k;
int map[102][102];

void input() {
    cin >> n;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cin >> map[i][j];
        }
    }
}
int count(){
    int num = 0;
    bool vis[102][102] = {{false,},};
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(map[i][j]==0 || vis[i][j]) continue;
            queue<pair<int,int>> q;
            vis[i][j] = true;
            q.push({i,j});
            ++num;
            while(!q.empty()){
                auto a = q.front(); q.pop();
                map[a.X][a.Y] = num;
                for(k=0;k<4;k++){
                    int ny = a.X + dy[k];
                    int nx = a.Y + dx[k];
                    if(ny<0||nx<0||ny>=n||nx>=n) continue;
                    if(map[ny][nx] && !vis[ny][nx]) {
                        vis[ny][nx] = true;
                        q.push({ny,nx});
                    }
                }
            }
        }
    }
    return num;
}

void get_dist(vector<int>& ret) {
    int dist[102][102];
    int mdist;
    for(i=0; i<n; i++){
        for(j=0;j<n;j++){
            for(int i=0;i<n;i++) fill(dist[i], dist[i]+n, -1);
            if(map[i][j] == 0) continue;
            x = map[i][j]; // 섬 번호
            mdist = LIM;
            bool found = false; // found closest distance
            queue<pair<int,int>> q;
            q.push({i,j});
            dist[i][j] = 0;
            while(!q.empty() && !found){
                auto a = q.front(); q.pop();
                for(k=0;k<4;k++){
                    int ny = a.X + dy[k];
                    int nx = a.Y + dx[k];
                    if(ny<0 || nx<0 || ny>=n || nx>=n) continue; // range
                    if(dist[ny][nx] >= 0 || x == map[ny][nx]) continue; // 동일한 섬이거나, 방문한 적 있으면 skip
                    if(map[ny][nx] != 0 && map[ny][nx] != x) {
                        mdist = dist[a.X][a.Y];
                        found = true;
                        break;
                    }
                    dist[ny][nx] = dist[a.X][a.Y]+1; // 바다여도 거리 +1 되는 중임
                    q.push({ny,nx});
                }
            }
            ret[x] = min(ret[x], mdist);
        }
    }
}

int main(void){
    PRE_PROC
    input();
    x = count(); // 섬의 개수를 반환 + 섬마다 (1~k)까지의 번호를 map에 부여
    vector<int> dist(x+1, LIM);
    get_dist(dist); // x개의 섬에서 지을수 있는 가장 가까운 다리까지의 거리
    vector<int>::iterator it = min_element(dist.begin(), dist.end());
    if(*it > 0) cout << *it << endl;
    else cout << "something wrong\n";
    return 0;
}