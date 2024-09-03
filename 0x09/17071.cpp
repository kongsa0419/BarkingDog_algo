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

#define PRE_PROC ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
using namespace std;
#define LMT 500'000

int sb, bro;
queue<tuple<int,int>> q;    // sb, time
int time[2][LMT+2]; // record time "[Time%2][where] = time"

inline bool oob(int x) {
    return (x<0 || x>LMT);
}

int main(void){
    PRE_PROC
    cin >> sb >> bro;

    for(int i=0;i<2;i++) fill(time[i], time[i]+LMT+2, -1);

    q.push({sb, 0});
    time[0][sb] = 0;
    // process subin 
    while(!q.empty())
    {
        int a,b; // subin, time
        tie(a,b) = q.front(); q.pop();
        b++; // 1 sec later
        for(int nxt : {a-1, a+1, a*2}) {
            if(oob(nxt)) continue;
            if(time[b%2][nxt] != -1) continue;
            time[b%2][nxt] = b;
            q.push({nxt, b});
        }
    }

    // process bro
    bool found = false;
    int now = 0;
    while (bro <= LMT) {
        if(time[now%2][bro] <= now) {
            found = true;
            break;
        }
        bro += ++now;
    }

    if(found) cout << now << '\n';
    else cout << -1 << '\n';
    return 0;
}