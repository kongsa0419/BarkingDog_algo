#include<iostream>
#include<algorithm>
#include<queue>

#define PRE_PROC ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
#define LMT 1505
#define X first
#define Y second
#define SWN 'L'
#define WTR '.'
#define ICE 'X'

using namespace std;

int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};
int n,m,i,j,k;
string map[LMT];
bool vis_wtr[LMT][LMT], vis_swn[LMT][LMT];
queue<pair<int,int>> wq1, wq2, sq1, sq2;
int sy, sx;
int day = 0;

bool oob (int y, int x) {return (y<0 || x<0 || y>=n || x>=m);}
void input(){
    cin >> n >> m;
    for(i=0;i<n;i++) cin >> map[i];
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(map[i][j] != ICE){
                wq1.push({i,j});
                vis_wtr[i][j] = true;
            }
            if (map[i][j] == SWN){
                sy=i; sx=j;
            }
        }
    }
    map[sy][sx] = WTR;
    sq1.push({sy,sx});
    vis_swn[sy][sx] = true;
}
void melt(){
    /* Q 2개 이용하여 얼음 인근의 물만 탐색하므로써 시간 단축 */
    while(!wq1.empty()){
        auto& a = wq1.front();
        for(k=0; k<4; k++){
            int ny = a.X + dy[k];
            int nx = a.Y + dx[k];
            if(oob(ny,nx) || vis_wtr[ny][nx]) continue;
            if(map[ny][nx]==ICE) {
                wq2.push({ny,nx});
                vis_wtr[ny][nx] = true;
            }
        }
        wq1.pop();
    }

    while(!wq2.empty()){
        auto& a = wq2.front();
        map[a.X][a.Y]=WTR;
        wq1.push(a);
        wq2.pop();
    }
}

bool meet(){
    while(!sq1.empty()){
        auto& a = sq1.front();
        for(k=0; k<4; k++){
            int ny = a.X+dy[k];
            int nx = a.Y+dx[k];
            if(oob(ny,nx) || vis_swn[ny][nx]) continue;
            if(map[ny][nx]==SWN){
                return true;
            } else if(map[ny][nx]!=ICE){
                sq1.push({ny,nx});
            } else {
                sq2.push({ny,nx});
            }
            vis_swn[ny][nx] = true;
        }
        sq1.pop();
    }
    std::swap(sq1,sq2);
    return false;
}
void printmap(){
    for (int i=0; i<n; i++) cout << map[i] << endl;
}

int main(void){
    PRE_PROC
    input();
    while(1){
        melt();
        day++;
        if(meet()) break;
    }
    cout << day << endl;
}