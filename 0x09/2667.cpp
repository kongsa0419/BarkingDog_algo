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
char map[27][27];
int  vis[27][27];
int n, i, j, k;
void run(){
    /* code HERE */
    int cnt = 0;  // 단지 수
    cin >> n;
    for(i=0;i<n;i++){
        cin >> map[i];
    }
    vector<int> vec;
    for(i=0; i<n; i++) {
        for (j=0;j<n;j++){
            if (map[i][j] == '1') {
                cnt++;
                int size = 0; // 단지 너비
                queue<pair<int,int>> q;
                q.push({i,j});
                while(!q.empty()) {
                    auto a = q.front(); q.pop();
                    size++;
                    map[a.X][a.Y] = '0';
                    for(k=0; k<4; k++) {
                        int ny = a.X + dy[k];
                        int nx = a.Y + dx[k];
                        if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
                        if (map[ny][nx] == '1') {
                            q.push({ny, nx});
                            map[ny][nx]  = '0'; // visit
                        }
                    }
                }
                vec.push_back(size);
            }
        }
    }
    sort(vec.begin(), vec.end(), less<int>());
    cout << cnt << '\n';
    for(const auto& a : vec) {
        cout << a << '\n';
    }
}
int main(void){
    PRE_PROC
    run();
    return 0;
}