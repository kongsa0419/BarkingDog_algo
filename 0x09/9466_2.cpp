#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

#define CYCLE -1
#define INIT   0

int main(void) {
    int tc;
    cin >> tc;
    while(tc--){
        int n, i, j, k;
        cin >> n;
        int map[n+1] = {INIT,};
        int vis[n+1] = {INIT,};
        for(i=1;i<=n;i++){
            cin >> map[i];
        }
        k = 0;
        for(i=1;i<=n;i++){
            if(vis[i] != INIT) continue;
            j = i;
            while(1) {
                vis[j] = i; // 그룹번호 i
                j = map[j];
                if(vis[j] == i){ // 이번 방문에서 지나간 학생에 도달했을 경우
                    while (vis[j] != CYCLE) {
                        vis[j] = CYCLE;
                        j = map[j];
                    }
                    break;
                }
                else if (vis[j] > 0) { // 중간에 낙오된 학생을 방문할 경우
                    // 앞선 vis[j] = i;가 visit의 의미도 나타냄
                    // vis[j] != CYCLE && vis[j] != INIT 이면 팀이 없음이 확실한 경우임
                    break; 
                }
            }
        }
        for(i=1;i<=n;i++){
            if(vis[i] != CYCLE) k++;
        }
        cout << k << endl;
    }
}
