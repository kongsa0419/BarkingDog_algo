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

#define X first 
#define Y second

#define PRE_PROC ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
using namespace std;
vector<pair<int,int>> orig, eggs;
int n;
int res=0;
int hits = 1;
void print_state() {
    cout << "HITS:" << hits++ << endl;
    cout << "---map) x, y---\n";
    for(auto a : eggs) {
        cout << a.X << ',' << a.Y << endl;
    }
    cout << "---------------\n";
}
// idx=왼손에 들 계란
void func(int idx) {
    print_state();

    if(idx == n) {
        // 정산 후 갱신
        int broken=0;
        for(int i=0; i<n; i++){
            if(eggs[i].X <= 0) broken++;
        }
        cout << "broken:" << broken << endl;
        if(broken > res) res = broken;
        return;
    }

    if(eggs[idx].X <= 0) {
        func(idx+1);
        return;
    }

    for(int i=0; i<n; i++) {
        if(i==idx || eggs[i].X <= 0) continue;

        eggs[idx].X -= eggs[i].Y;
        eggs[i].X -= eggs[idx].Y;
        func(i);
        eggs[idx].X += orig[i].Y;
        eggs[i].X += orig[idx].Y;
    }
}

int main(void){
    PRE_PROC
    int hp, attk;
    cin >> n;
    eggs.resize(n);
    orig.resize(n);
    for(int i=0; i<n; i++){
        cin >> hp >> attk;
        eggs[i] = {hp, attk};
        orig[i] = {hp, attk};
    }
    func(0);
    cout << res << endl;
    return 0;
}