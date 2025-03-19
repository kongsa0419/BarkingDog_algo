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
#define OK  0
#define NOK -1
#define X first
#define Y second
#define PRE_PROC ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
using namespace std;

int cc=0;
int result = 0; //maximum
int n,nn,x;
int map[100];
int cross1[20], cross2[20]; // 19까지만 있어도 됌
/*
queue<pair<int,int>> q[100];
int dy[4] = {-1,-1,1,1};
int dx[4] = {-1,1,-1,1};
*/

bool oob (int y, int x) {
    return (y<0 || x<0 || y>=n || x>=n);
}

// lv= vishop count, idx = serach offset
void func(int lv, int idx) {
    for(int i=idx; i<nn; i++) {
        int nlv, r, c;
        nlv = lv+1;
        r = i/n;
        c = i%n;

        if(map[i]!=OK || cross1[r+c]!=OK || cross2[r-c+(n-1)]!=OK) continue;
        
        // Occasion1: when you put vishop here
        map[i] = nlv;
        cross1[r+c] = nlv;
        cross2[r-c+(n-1)] = nlv;
        func(lv+1, i+1);

        //occasion2: when you don't put vishop here
        map[i] = 0;
        cross1[r+c] = 0;
        cross2[r-c+(n-1)] = 0;
        func(lv, i+1);
    }
    if(lv > result) result = lv;
}

int main(void){
    PRE_PROC
    n=nn=x=0;
    cin >> n;
    nn = n*n;
    for(int i=0; i<nn; i++) {
        cin >> x; 
        map[i] = ((x==0) ? NOK : OK);
    }
    func(0, 0);
    cout << result << '\n';
    return 0;
}