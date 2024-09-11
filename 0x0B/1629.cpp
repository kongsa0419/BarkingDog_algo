/**
 * name:    
 * solved:  N
 * 재귀를 활용해서 풀면 되는데, 27번쨰 줄에 pow2()함수 호출을 한번만 한다.
 * 원래 수식대로 코드짜서 저 pow2(b/2)를 2번을 호출했는데 실패했다.
 * map으로 값을 기록해놨는데도 실패하는걸 봐선 b값이 너무 커지면 그만큼 함수호출이 커져 오버헤드가 큰가보다.
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


using ll = long long;

ll a,b,c;
map<ll,ll> m; // BST(Red-Black Tree)

ll pow2(ll b) {
    if(b==1) return a%c;
    ll val;
    val = pow2(b/2) % c;
    val = (val * val) % c;
    if(b%2) {
        val = ( (a%c) * val ) % c;
    }
    return val;
}
int main(void){
    PRE_PROC
    cin >> a >> b >> c;
    cout << pow2(b);
    return 0;
}