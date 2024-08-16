#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

#define CYCLE 1
#define VISIT 0

int main(void) {
    int tc;
    cin >> tc;
    while(tc--){
        int n, i, j, k;
        cin >> n;
        vector<int> map;
        vector<int> vis(n+1, -1);
        map.reserve(n+1); // 1~n
        for(i=1;i<=n;i++){
            cin >> map[i];
        }
        vector<int> record; 
        for(i=1;i<=n;i++){
            if(vis[i] == -1) {
                record.clear();
                j = i;
                while(true) {
                    if(j==map[j]) { // cycle없음 => 
                        vis[j] = CYCLE;
                        for(int a : record) vis[a] = VISIT;
                        break;
                    }
                    if(vis[j] >= 0) {
                        for(int a : record) vis[a] = vis[j];
                        break;
                    }
                    if (i==map[j]) { //cycle있음 => record 원소들을 모두 CYCLE 처리
                        for(int a : record) vis[a] = CYCLE;
                        break;
                    }
                    record.push_back(j);
                    j = map[j];
                }
            }
        }
        k=0;
        for(i=1; i<=n; i++){
            if(vis[i] == VISIT) k++;
        }
        cout << k << endl;
    }
}