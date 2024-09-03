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
}

int main(void){
    PRE_PROC
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
    return 0;
}