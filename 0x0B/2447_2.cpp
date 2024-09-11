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

void func(const int& n, const int& y, const int& x)
{
    if ((y/n)%3==1 && (x/n)%3==1) {
            cout << ' ';
    } else{
        if (n==1) {
            cout << '*';
        } else {
            func(n/3, y, x);
        }
    }
}

int main(void){
    PRE_PROC
    int n;
    int i,j;
    cin >> n;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            func(n/3, i, j);
        }
        cout << '\n';
    }
    return 0;
}