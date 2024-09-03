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
#define uint unsigned int 

uint n, m, x;

uint get_safety(uint x){ // 안전거리
   int cnt=0;
   uint o = n;
   while(o > 0){
        if(o%2 != x%2) cnt++;
        o >>= 1;
        x >>= 1;
   }
   return cnt;
}

int main(void){
    PRE_PROC
    // uint min_sfty = 2'147'000'000;
    uint min_sfty = 0;
    cin >> n >> m;
    while(m--) {
        cin >> x;
        min_sfty = max(min_sfty, get_safety(x));
    }   
    cout << min_sfty << endl;
}