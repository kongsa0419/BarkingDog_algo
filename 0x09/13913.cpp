#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<tuple>

#define X first
#define Y second
#define PRE_PROC ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
using namespace std;
#define LMT 100'000
int sb, bro, i, j, k;
int parent[LMT+2];
int dist[LMT+2];
queue<int> q;

int main(void){
    PRE_PROC
    cin >> sb >> bro;
    fill(dist,dist+LMT+2, -1); //
    dist[sb] = 0;
    q.push(sb);
    while(!q.empty()){
        i = q.front(); q.pop();
        if(i!=0 && i*2 <= LMT && dist[i*2]<0) {
            dist[i*2] = dist[i]+1;
            parent[i*2] = i;
            q.push(i*2);
        }
        for(int nxt : {i-1, i+1}) {
            if(nxt<0 || nxt>LMT) continue;
            if(dist[nxt]>=0) continue;
            dist[nxt] = dist[i]+1;
            parent[nxt] = i;
            q.push(nxt);
        }
        if(dist[bro] >= 0) break;
    }
    /* 경로 찾기 */
    stack<int> s;
    k = bro;
    while(k != sb) {
        s.push(k);
        k = parent[k];
    }
    s.push(k); // 첫 시발점 포함

    cout << dist[bro] << '\n';
    while(!s.empty()) {
        cout << s.top() << ' '; s.pop();
    }
    cout << '\n';
    return 0;
}