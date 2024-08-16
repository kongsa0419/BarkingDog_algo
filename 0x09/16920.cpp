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
#define LMT 1000
#define EMPTY 0
#define BLOCK -1
#define PRE_PROC ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
using namespace std;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
int map[LMT+2][LMT+2];
deque<tuple<int,int,int>> points[11]; // 매 round마다 player별 좌표를 초기화할 곳
int n,m,p,i,j;
bool go = false;    // gameover
int go_p = 0;       // gameover player count
bool go_r[10];      // gameover record
int pa[10];         // player availability
char ch;


void input() {
    cin >> n >> m >> p;
    for(i=1; i<=p; i++) cin >> pa[i];
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cin >> ch;
            if(ch=='.') map[i][j] = EMPTY; //빈 칸
            else if (ch == '#') map[i][j] = BLOCK; // block
            else {
                map[i][j] = ch - '0'; // 1 ~ 9
                points[map[i][j]].push_back({i,j,0});
            }
        }
    }
}

/* (N x M)을 돌며 영토를 구하고, 출력하는 함수 */
void result() {
    vector<int> ter(p+1, 0);
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            int num = map[i][j];
            if(num <= 0) continue;
            ter[num]++;
        }
    }
    for(i=1;i<=p;i++){
        cout << ter[i] << ' ';
    } cout << '\n';
    return;
}

/* plyr가 pa[plyr]에 맞춰 확장한 영토개수 */
int expand(int p) {
    deque<tuple<int,int,int>> tmp;
    int y,x,s, ny,nx;
    int cnt = 0;

    std::swap(points[p], tmp);
    while(!tmp.empty()) {
        tie(y,x,s) = tmp.front(); tmp.pop_front();
        for(int d=0; d<4; d++) {
            ny = y + dy[d];
            nx = x + dx[d];
            if(ny<0 || nx<0 || ny>=n || nx>=m) continue;
            if(s >= pa[p]) continue;
            if(map[ny][nx] != EMPTY) continue;
            map[ny][nx] = p;
            points[p].push_back({ny,nx,0});             // expand()함수 이후로 추가된 모든 좌표
            tmp.push_back({ny,nx,s+1});
            cnt++;
        }
    }
    return cnt;
}

int main(void){
    PRE_PROC
    input();
    int plyr = 0, cnt;
    while(!go){
        plyr = (plyr % p) + 1;  // 1~p까지의 숫자
        if(go_r[plyr]) continue;// 이미 gameover된 플레이어
        cnt = expand(plyr);     // plyr가 pa[plyr]에 맞춰 확장한 영토개수
        if(cnt==0) {
            go_r[plyr] = true;
            go_p++;
            if(go_p == p) go = true;
        }
    }
    result(); // (N x M)을 돌며 영토를 구하고, 출력하는 함수
    return 0;
}