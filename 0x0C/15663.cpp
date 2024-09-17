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

int a1[10];
int a2[10];
int vis[10];

int n,m,i;

void func(const int& lv, set<vector<int>>& mset) {
    if(lv==m) {
        mset.insert(vector<int>(a2, a2+m));
        return;
    }

    for(int i=0; i<n; i++) {
        if(vis[i]) continue;
        vis[i] = 1;
        a2[lv] = a1[i];
        func(lv+1, mset);
        vis[i] = 0;
    }
}
int main(void){
    PRE_PROC
    cin >> n >> m;
    for(i=0;i<n;i++){
        cin >> a1[i];
    }
    set<vector<int>> mset;
    sort(a1, a1+n, less<int>());
    func(0, mset);
    for(auto a : mset) {
        for(auto d: a) {
            cout << d << ' ';
        }
        cout << '\n';
    }
    return 0;
}