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
void func(const int& n, const int& m, const int& sel, int arr[], bool vis[]) {
    int i;
    if(sel >= m){
        //print
        for(i=0; i<m; i++){
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(i=1; i<=n; i++) {
        if(vis[i]) continue;
        vis[i]=true;
        arr[sel]=i;
        func(n,m,sel+1, arr, vis);
        vis[i]=false;  
    }
}
int main(void){
    PRE_PROC
    int n, m;
    cin >> n >> m;
    int arr[n+2] = {0,};
    bool vis[n+2] = {false, };
    func(n,m,0,arr,vis);
    return 0;
}