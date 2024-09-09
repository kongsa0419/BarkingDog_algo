/**
 * name:    
 * solved:  N
 * 하노이 움직임 수 계산하는법
 * endl 대신 '\n'쓰니까 통과되네;;;;
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

void hanoi(const int& n, const int& src, const int& dst){
    if(n==1) { // BASE CONDITION
        cout << src << ' ' << dst << '\n';
        return;
    }
    hanoi(n-1, src, 6-src-dst);
    cout << src << ' ' << dst << '\n';
    hanoi(n-1, 6-dst-src, dst);
}
int main(void){
    PRE_PROC
    int n;
    cin >> n;
    cout << (1<<n) - 1 << '\n'; // 2^n - 1
    hanoi(n, 1,3);
    return 0;
}