#include <iostream>
#define PRE_PROC ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
#define LMT 2*14-1
using namespace std;

int n, cnt{0};
bool vis1[LMT]; // 행
bool vis2[LMT]; // (\)
bool vis3[LMT]; // (/)
void func(int lv) {
    if(lv == n) {
        cnt++;
        return;
    }
    
    for(int i=0; i<n; i++) {
        if(vis1[i] || vis2[i-lv+n-1] || vis3[i+lv]) continue;

        vis1[i]=true;
        vis2[i-lv+n-1] = true;
        vis3[i+lv] = true;
        func(lv+1);
        vis1[i]=false;
        vis2[i-lv+n-1] =false;
        vis3[i+lv] = false;
    }
}
int main(void){
    PRE_PROC
    cin >> n;
    func(0);
    cout << cnt << '\n';
    return 0;
}