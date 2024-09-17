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
#include<set>

#define PRE_PROC ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
using namespace std;

int n,m,i;
int a[10];
int b[10];
int vis[10];
set<vector<int>> mset;

void func(int lv, int st) {
    if(lv==m) {
        mset.insert(vector<int>(b, b+m));
        return;
    }

    for(int i=st; i<n; i++) {
        if(vis[i]) continue;
        vis[i]=1;
        b[lv]=a[i];
        func(lv+1, i+1);
        vis[i]=0;
    }
}
int main(void){
    PRE_PROC
    cin >> n >> m;
    for(i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a, a+n, less<int>());
    func(0,0);
    for(auto d : mset){
        for(auto dd: d) {
            cout << dd << ' ';
        }
        cout << '\n';
    }
    return 0;
}