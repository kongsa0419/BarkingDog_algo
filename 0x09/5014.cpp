/**
 * name:    
 * solved:  N
 * F층건물, G층회사, S층 현위치, U층 상승버튼, D층 하강버튼
 * 출력: 버튼 입력횟수. 도달 못할시  "use the stairs" 출력
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
#define LIMIT 1'000'000
using namespace std;

int dx[4] = {1, 0, -1, 0};
int vis[LIMIT + 2]; 
int F,G,S,U,D;
inline bool checkIdx(const int& pos) {
    return (pos >= 1 && pos <= F);
}

void run(){
    /* code HERE */
    cin >> F >> S >> G >> U >> D;
    queue<pair<int, int>> q;
    q.push({S, 0});
    vis[S] = 1;
    while(!q.empty()){
        auto a = q.front(); q.pop();
        if (a.X == G) {
            cout << a.Y << '\n';
            return;
        }
        if (checkIdx(a.X + U) && !vis[a.X + U]) {
            q.push({a.X + U, a.Y + 1});
            vis[a.X + U] = 1;
        }
        if (checkIdx(a.X - D) && !vis[a.X - D]) {
            q.push({a.X - D, a.Y + 1});
            vis[a.X - D] = 1;
        }
    }
    cout << "use the stairs\n";
}
int main(void){
    PRE_PROC
    run();
    return 0;
}