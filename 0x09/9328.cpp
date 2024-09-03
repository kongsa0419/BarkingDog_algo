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
#define LMT 105
#define EMPTY '.'
#define BLOCK '*'
#define DOCU '$'
#define ALPHA_SIZE 26

#define PRE_PROC ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
using namespace std;

// a = 97, A = 65
// z = 122 Z = 90

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
char map[LMT][LMT];
int vis[LMT][LMT];
int n, m;
int steal; // 훔칠 수 있는 문서 최대 개수
string s_key;
vector<int> keys; // boolean으로 바꿔도 무관(반복사용o)
queue<pair<int,int>> q;

void init() {
    n = m = steal = 0;
    queue<pair<int,int>> clean;
    std::swap(clean, q);
    for(int i=0; i<LMT; i++){
        fill(map[i], map[i] + LMT, 0);
        fill(vis[i], vis[i] + LMT, 0);
    }
    keys.assign(ALPHA_SIZE, 0);
}

void input() {
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> map[i][j];
        }
    }
    cin >> s_key;
    if(s_key == "0") return;
    for(char ch : s_key) {
        keys[ch-'a']++;
    }
}

void play() {
    queue<pair<int,int>> remain[26]; // 아직 키가 없지만 나중에 뚫을 곳들(알파벳별)

    q.push({0,0});
    vis[0][0] = 1;   
    while(!q.empty()) {
        int i,j;
        tie(i,j) = q.front(); q.pop();

        for(int k=0; k<4; k++){
            int ny = i + dy[k];
            int nx = j + dx[k];
            if(ny<0 || nx <0 || ny > n+1 || nx > m+1) continue;
            if(vis[ny][nx]) continue;
            if(map[ny][nx]==BLOCK) continue;
            
            if(isalpha(map[ny][nx])){
                if(isupper(map[ny][nx])){
                    // door
                    int idx = map[ny][nx] - 'A';
                    if(!keys[idx]) {
                        remain[idx].push({i,j});
                        continue;
                    }
                } else{
                    // key
                    int idx = map[ny][nx] - 'a';
                    keys[idx]++;
                    while(!remain[idx].empty()) {
                        auto a = remain[idx].front(); 
                        remain[idx].pop();
                        q.push({a.X, a.Y});
                        vis[a.X][a.Y]++;
                    }
                }
            } else if (map[ny][nx]==DOCU) steal++;

            vis[ny][nx] = true;
            q.push({ny,nx});
        }
    }

    cout << steal << endl;
}

int main(void){
    PRE_PROC
    int tc;
    cin >> tc;
    while(tc--){
        init();
        input();
        play();
    }
    return 0;
}