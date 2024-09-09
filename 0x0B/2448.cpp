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

void func(int step, int y, int x)
{
    if()

}

int main(void){
    PRE_PROC
    int x, k, tmp;
    cin >> x;
    tmp = x/3;
    k = 0;
    while(tmp != (1 << k)){
        k++;
    }
    int n = tmp*6; // star'*' 5개 + blank' 개
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            func(k, i, j);
        }
        cout << '\n';
    }
    return 0;
}