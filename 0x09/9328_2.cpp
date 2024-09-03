#include<iostream>
#include<algorithm>
#include<queue>
#include<string>
#include<memory>

#define X first
#define Y second
#define LMT 105
using namespace std;

int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};

char map[LMT][LMT];
bool vis[LMT][LMT];
int tc, n, m;
string skey;
bool keys[26];

void input(){
    int i,j;

    cin >> n >> m;
    for(i=0;i<=n+1;i++){
        fill(map[i], map[i]+LMT, 0);
        fill(vis[i], vis[i]+LMT, false);
    }
    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            cin >> map[i][j];
        }
    }    
    fill(keys, keys+26, false);
    cin >> skey;
    if(skey=="0") return;
    for(char ch : skey){
        keys[ch-'a'] = true;
    }
}

void play() {
    queue<pair<int,int>> q;
    queue<pair<int,int>> remain[26];
    int steal = 0;

    q.push({0,0});
    vis[0][0] = true;
    while(!q.empty()){
        int i,j;
        tie(i,j) = q.front(); q.pop();
        for(int k=0; k<4; k++){
            int ny = i+dy[k];
            int nx = j+dx[k];
            if(ny<0 || nx<0 || ny>n+1 || nx>m+1) continue;
            if(vis[ny][nx]) continue;
            if(map[ny][nx]=='*') continue;

            char ch = map[ny][nx];
            if(isalpha(ch)){
                if(islower(ch)){
                    if(!keys[ch-'a'])
                        keys[ch-'a'] = true;
                    while(!remain[ch-'a'].empty()){
                        auto r = remain[ch-'a'].front();
                        remain[ch-'a'].pop();
                        vis[r.X][r.Y] = true;
                        q.push({r.X, r.Y});
                    }
                } else if(!keys[ch-'A']) {
                    remain[ch-'A'].push({ny,nx});
                    continue;
                }
            } else if (ch=='$'){
                steal++;
            }
            vis[ny][nx] = true;
            q.push({ny,nx});
        }
    }

    cout << steal << endl;
}

int main(void) {
    cin >> tc;
    while(tc--) {
        input();
        play();
    }
    return 0;
}