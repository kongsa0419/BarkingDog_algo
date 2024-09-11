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
#include<map>
#define PRE_PROC ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
using namespace std;

int n;
int cnt=0;
vector<pair<int,int>> v;

void hanoi(int x, int src, int dst){
    if(x==1) {
        cnt++;
        v.push_back({src, dst});
        return;
    }
    hanoi(x-1, src, 6-src-dst);
    cnt++;
    v.push_back({src, dst});
    hanoi(x-1, 6-src-dst, dst);
}
int main(void){
    PRE_PROC
    cin >> n;
    hanoi(n, 1, 3); // n번째 원판을 1에서 3으로 옮기는 함수
    cout << cnt << endl;
    for(auto a : v){
        cout << a.first << ' ' << a.second << endl;
    }
    return 0;
}