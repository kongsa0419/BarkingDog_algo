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

#define PRE_PROC ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
using namespace std;

int n;
vector<int> v,bits;
int main(void){
    PRE_PROC
    
    while(1) {
        cin >> n;
        if(n==0) break;
        v.resize(n); bits.resize(n);
        for(int i=0; i<n; i++){
            cin >> v[i];
            if(i<6) bits[i] = 1;
        }

        do {
            for(int i=0; i<n; i++){
                if(!bits[i]) continue;
                cout << v[i] << ' ';
            } cout << '\n';
        } while(prev_permutation(bits.begin(), bits.end()));

        cout << '\n';
    }
    return 0;
}