/**
 * name:    
 * solved:  N
 * 그냥 처음 원소풀을 중복없이 받으면 됐었네...
 */

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<set>
#include<tuple>

#define PRE_PROC ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
using namespace std;

int n,m,x;
int a[10];
int b[10];

void func(int lv){
    if(lv==m){
        for(int i=0; i<m; i++) {    
            cout << b[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i=0;i<n;i++){
        b[lv]=a[i];
        func(lv+1);
    }
}
int main(void){
    PRE_PROC
    set<int> set1;
    cin >> n >> m;
    
    int last=0;
    for(int i=0; i<n; i++) {
        cin >> x;
        if(set1.find(x)!=set1.end()) {} 
        else {
            a[last++] = x;
            set1.insert(x);
        }
    }
    n = set1.size();
    sort(a, a+n, less<int>());

    func(0);
    
    return 0;
}