#include <iostream>
#include <vector>
#define PRE_PROC ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
#define LMT 2*14-1
using namespace std;

vector<int> rec;

// y번째 원소로 x를 넣으려고함.
void func(int y, int x, const int& n, int& cnt) {
    //validate
    int i;
    for(i=0; i<y; i++) {
        if(rec[i]==x) return;
        if((y+x)==(i+rec[i]) || abs(y-i) == abs(x-rec[i])) return;
    }
    
    if(y==n-1) {cnt++; return;}

    //Backtrace
    rec[y] = x;
    for(i=0; i<n; i++) {
        func(y+1, i, n, cnt);
    }
    rec[y] = -1;
}
int main(void){
    PRE_PROC
    int n, cnt{0};
    cin >> n;
    rec.resize(n, -1);
    for(int i=0; i<n; i++) {
        func(0, i, n, cnt);
    }
    cout << cnt << '\n';
    return 0;
}