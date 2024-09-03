/**
 * name:    
 * solved:  N
*/

#include<iostream>
#include<queue>
#include<vector>
#define LMT 1'000'005

using namespace std;

int n,m, i,j;
int rec[LMT];
int get_max_bits() {
    int x = n;
    int cnt = 1;
    while(x){
        x /= 2;
        cnt++;
    }
    return cnt;
}
int main(void){
    cin >> n >> m;
    fill(rec, rec+n+2, -1);
    queue<int> q; 
    for(i=0;i<m;i++){
        cin >> j;
        q.push(j);
        rec[j]=0;
    }

    int nbit = get_max_bits();
    while(!q.empty()){
        int x = q.front(); q.pop();
        // x의 각 비트를 반전시킨 값 nx에 대해,
        // rec[nx] = rec[x]+1임. (안전거리가 x로부터 1로 고정)
        for(int d=0; d < nbit; d++){
            int nx;
            if(x & 1 << d){
                // d번째 digit이 1이라면
                nx = x & ~(1 << d);
            } else {
                // d번째 digit이 0이라면
                nx = x | (1 << d);
            }
            if(nx < 0 || nx > n) continue;
            if(rec[nx] != -1) continue;
            rec[nx] = rec[x] + 1;
            q.push(nx);
        }
    }

    int res = 0;
    for(i=0; i<=n; i++){
        res = max(res, rec[i]);
    }
    cout << res << endl;

    return 0;
}