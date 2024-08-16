/**
 * name:    
 * solved:  N
 * 
    '.': 빈 공간
    '#': 벽
    '@': 상근이의 시작 위치
    '*': 불

 * 오답노트: 
 * 실패 원인: BFS 와중 q에서 front(); pop(); 콤보 시, q.front() 할때 참조자 &를 써버리면 q.pop()과 동시에 소멸될 가능성이 있음.
 * 중요! {'.'(46), '#'(35), '@'(64), '*'(42)}의 문자가 남아있는 map[][]에 0부터 1씩 증가하는 배열로 바꾸게 되면 35칸만 지나도 35(char)가 되어 오류 가능성있음.
 * 로직문제:    (map[a.X][a.Y] - '0' + 1)이라고 써야할 것을 (map[a.X][a.Y] + 1) 라고 써서 오래 헤멤
 * 메모리초과:  
 * 
 *  1) q에 불필요하게 과도한 연산/추출을 하는 경우... q2(상근이가 갈 수 있는 곳 파악하는 곳) 푸쉬 조건 수정
 *      1.벽x
 *      2. 빈 공간일 것 <== 틀린 조건
 *      3. fire가 퍼지는 시간보다 이르게 해당 공간으로 도착해야함
 *  2) q2에 남은 원소들이 다음 TC에 영향끼칠까? clear해도 소용없음.
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
int n, m, i, j, k;
int map[1003][1003];   // pass or no
int vis1[1003][1003];  // fire
int vis2[1003][1003];  // SG
char ch;
void dbg() {
    cout << "=--------=\n";
    cout << "[map]\n";
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << "[fire]\n";
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cout << vis1[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << "[SG]\n";
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cout << vis2[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << "=--------=\n";
}
void play() {
    n = m = i = j = k = 0;
    cin >> m >> n;
    for(i=0;i<n;i++) { // init
        fill(map[i], map[i]+m, 0);
        fill(vis1[i], vis1[i]+m, 0);
        fill(vis2[i], vis2[i]+m, 0);
    }
    queue<pair<int,int>> q1, q2;
    for(i=0; i<n; i++){ //input
        for(j=0;j<m;j++){
            cin >> ch;
            if(ch=='#') {
                map[i][j] = -1; // cannot pass
            } else {
                map[i][j] = 0;  // pass
                if (ch == '*'){ 
                    q1.push({i,j});
                    vis1[i][j] = 1;
                } else if (ch == '@') {
                    q2.push({i,j});
                    vis2[i][j] = 1;
                }
            }
        }
    }
    while(!q1.empty()) { // fire dist
        auto a = q1.front(); q1.pop();
        for(k=0; k<4; k++){
            int ny = a.X + dy[k];
            int nx = a.Y + dx[k];
            if (ny<0 || nx<0 || ny>=n || nx>=m) continue;
            if (map[ny][nx] == -1 || vis1[ny][nx] > 0) continue;
            vis1[ny][nx] = vis1[a.X][a.Y]+1;
            q1.push({ny,nx});
        }
    }
    // get SG dist
    while(!q2.empty()) {
        auto a = q2.front(); q2.pop();
        for(k=0; k<4; k++){
            int ny = a.X + dy[k];
            int nx = a.Y + dx[k];
            if (ny<0 || nx<0 || ny>=n || nx>=m) {   // goal
                cout << (vis2[a.X][a.Y]) << '\n';
                return;
            }
            if (map[ny][nx]  == -1) continue;
            if (vis2[ny][nx]) continue;
            if (vis1[ny][nx] > 0 && (vis1[ny][nx] <= vis2[a.X][a.Y] + 1)) continue;
            vis2[ny][nx] = vis2[a.X][a.Y] + 1;
            q2.push({ny,nx});
        }
    }
    cout << "IMPOSSIBLE\n";
}
void run(){
    /* code HERE */
    int tc;
    cin >> tc;
    while(tc--){
        play();
    }
}
int main(void){
    PRE_PROC
    run();
    return 0;
}