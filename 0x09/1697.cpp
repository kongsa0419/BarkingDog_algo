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
bool vis[100'005];
int sb, bro;
void run(){
    /* code HERE */
    cin >> sb >> bro;
    queue<pair<int,int>> Q;
    Q.push({sb, 0});
    vis[sb] = 0;
    while(!Q.empty()) {
        auto& a = Q.front(); Q.pop();
        if (a.X == bro) {
            cout << a.Y << '\n';
            return;
        }
        if (!vis[a.X + 1] && a.X + 1 >= 0 && a.X + 1 <= 100'000) {
            Q.push({a.X + 1, a.Y + 1});
            vis[a.X + 1] = true;
        }
        if (!vis[a.X - 1] && a.X - 1 >= 0 && a.X - 1 <= 100'000) {
            Q.push({a.X - 1, a.Y + 1});
            vis[a.X - 1] = true;
        }
        if (!vis[a.X * 2] && a.X * 2 >= 0 && a.X * 2 <= 100'000) {
            Q.push({a.X * 2, a.Y + 1});
            vis[a.X * 2] = true;
        }
    }
    return;
}
int main(void){
    PRE_PROC
    run();
    return 0;
}