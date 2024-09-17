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

int n,m,x;
vector<int> arr;
vector<int> num;
void func(int lv, int st) {
    if(lv==m) {
        for(auto n : num) {
            cout << n << ' ';
        }
        cout<< '\n';
        return;
    }

    for(int i=st; i<n; i++){
        num[lv]=arr[i];
        func(lv+1, i);
    }
}
int main(void){
    PRE_PROC
    cin >> n >> m;
    set<int> s;
    for(int i=0; i<n; i++) {
        cin >> x;
        s.insert(x);
    }
    n = s.size();
    num.resize(m);
    arr.assign(s.begin(), s.end());
    func(0,0);
    return 0;
}