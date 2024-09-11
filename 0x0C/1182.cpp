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

int n, goal, cnt{0};
vector<int> v;
bool vis[24];
void func(int lv, int sum) {
    if(lv==n){
        if(sum==goal) {
            cnt++;
        }
        return;
    }
    func(lv+1, sum+v[lv]);  // used v[lv]
    func(lv+1, sum);        // not used v[lv]
}
int main(void){
    PRE_PROC
    cin >> n >> goal;
    v.resize(n);
    for(int i=0; i<n; i++) {
        cin >> v[i];
    }
    func(0, 0);
    if(goal==0) cnt--;
    cout << cnt << '\n';
    return 0;
}