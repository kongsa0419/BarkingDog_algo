/**
 * name:    
 * solved:  N
<<<<<<< HEAD
=======
 * bfs는 queue에 입출력 연산 수를 줄여야만 한다
>>>>>>> 79e541ee7d4a09fc9a10a17455c0c24822a7db04
 */

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<tuple>

<<<<<<< HEAD
#define LMT 100'000
#define PRE_PROC ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
using namespace std;

int vis[LMT+1]; // dist
int sb, bro, i, t;
queue<int> Q;

// px2에 해당하는 곳까지 visit
void teleport(int p, int t) {
    int nxt = p*2;
    cout << "nxt: ";
    while(nxt <= LMT && vis[nxt] == 0) {
        cout << nxt << ',';

        Q.push(nxt);
        vis[nxt] = t;
        if (nxt > bro) break;
        nxt *= 2;
    }
    cout << "time: " << t << '\n';
=======
#define X first
#define Y second
#define PRE_PROC ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
using namespace std;

const int LMT = 100'000;
int dist[LMT+2];
int sb, bro, i, j, t;
queue<int> q;

inline bool oob(int x) {return (x<0 || x>LMT);}

void teleport(int x){
    /* x의 2배 되는 거리마다 dist[x]로 채워줌 */
    if(x==0) return;

    int nxt = x;
    while(1){
        nxt *= 2;
        if(nxt>LMT) break;
        if(dist[nxt]) continue; // 이 조건 없으면 fail
        dist[nxt] = dist[x];
        if(dist[bro]) break;
        q.push(nxt);
    }
    return;
>>>>>>> 79e541ee7d4a09fc9a10a17455c0c24822a7db04
}

int main(void){
    PRE_PROC
<<<<<<< HEAD
    cin >> sb >> bro;
    Q.push(sb);
    vis[sb] = 1;
    while(!Q.empty() && vis[bro] == 0) {
        int pos = Q.front(); Q.pop();
        teleport(pos, vis[pos]);
        if(vis[sb+1] == 0) {
            vis[sb+1] = vis[sb] + 1;
            Q.push(sb+1);
        }
        if(vis[sb-1] == 0) {
            vis[sb-1] = vis[sb] + 1;
            Q.push(sb-1);
        }
    }
    cout << vis[bro]-1 << endl;
    cout << "dist)";
    for(i=0;i<=bro; i++) {
        cout << vis[i] << ' ';
    }
    cout << '\n';
=======
    /* code HERE */
    cin >> sb >> bro;
    dist[sb] = 1;
    q.push(sb);
    while(!q.empty()) {
        i = q.front(); q.pop();
        if(dist[bro]) break;
        teleport(i);
        int dir[] = {i-1, i+1};
        for(j=0;j<2;j++){
            t = dir[j];
            if(oob(t) || dist[t]) continue;
            dist[t] = dist[i]+1;
            q.push(t);
            teleport(t);
        }
    }
    cout << dist[bro] - 1 << '\n';

>>>>>>> 79e541ee7d4a09fc9a10a17455c0c24822a7db04
    return 0;
}