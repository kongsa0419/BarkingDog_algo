#include<iostream>
#include<vector>
#define PRE_PROC ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

vector<int> vec;
int n, cnt{0};
bool valid(int r, int c) {
    for(int i=1; i<r; i++) {
        if(vec[i]==c) return false;
        if(r+c == i+vec[i] || abs(r-i) == abs(c-vec[i])) return false;
    }
    return true;
}
void func(int lv) {
    if(lv==n+1) {cnt++; return;}
    int i;
    for(i=1; i<=n; i++) {
        // row = lv에서 col=i에 퀸을 둘 수 있는지 확인
        if(!valid(lv, i)) continue;
        vec[lv]=i;
        func(lv+1);
        vec[lv]=0;
    }
}
int main(void) {
    cin >> n;
    vec.resize(n+1);
    func(1);
    cout << cnt << endl;
    return 0;
}