/**
 * name:    일곱 난쟁이
 * solved:  Y
 */
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<stack>
#define PRE_PROC ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
using namespace std;

bool DFS(vector<int>& dwf, vector<int>& res, const int& idx, const int& cnt, const int& tot) {
    // 현재까지 total length == 100이면 return true;
    if (tot == 100 && cnt == 7) return true;
    
    // 더 탐색할 의미가 없다면 return false;
    if (idx >= 9 || cnt >= 7 || tot > 100) return false;

    // 탐색 1 (dwf[idx]를 난쟁이로 인정한 경우)
    res[cnt] = dwf[idx];
    if (DFS (dwf, res, idx + 1, cnt + 1, tot + dwf[idx])) return 1;
    // 탐색 2 (dwf[idx]를 난쟁이로 인정하지 않는 경우)
    res[cnt] = 0;
    if (DFS (dwf, res, idx + 1, cnt, tot)) return 1;

    // return false;
    return false;
}
// res에 키가 총합 100인 sh원소들로 채우는 함수
void run(){
    /* code HERE */
    vector<int> dwarfs(9, 0);
    for(int i=0; i<9; i++){
        cin >> dwarfs[i];
    }
    vector<int> res(7,0);  // real dwarfs
    if (DFS(dwarfs, res, 0, 0, 0)) {
        sort(res.begin(), res.end());
        for (auto& a : res) cout << a << '\n';
    }else {
        cout << "something wrong\n";
    }
    return;
}
int main(void){
    PRE_PROC
    run();
    return 0;
}