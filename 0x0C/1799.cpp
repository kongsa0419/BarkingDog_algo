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
// bool cross1[20], cross2[20]; // 19까지만 있어도 됌
queue<pair<int,int>> q[100];
int dy[4] = {-1,-1,1,1};
int dx[4] = {-1,1,-1,1};

bool oob (int y, int x) {
    return (y<0 || x<0 || y>=n || x>=n);
}

// lv= vishop count, idx = serach offset
void func(int lv, int idx) {
    for(int i=idx; i<nn; i++) {
        if(map[i] != OK) continue;
        int nlv, r, c;
        nlv = lv+1;
        r = i/n;
        c = i%n;
        
        map[i] = nlv;
        q[nlv].push({r,c});
        for(int k=0; k<4; k++){
            int step = 1;
            while(1) {
                int ny, nx;
                ny = r + dy[k]*step;
                nx = c + dx[k]*step;
                if(oob(ny,nx)) break;
                step++;
                if(map[ny*n + nx] != OK) continue;
                map[ny*n + nx] = nlv;
                q[nlv].push({ny,nx});
            }
        }
        // Occasion1: when you put vishop here
        func(lv+1, i+1);

        //occasion2: when you don't put vishop here
        map[i]=OK;
        while(!q[nlv].empty()) {
            auto& a = q[nlv].front();
            map[a.X*n + a.Y] = OK;
            q[nlv].pop();
        }
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