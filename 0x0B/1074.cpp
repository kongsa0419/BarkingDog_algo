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
using namespace std;
#define PRE_PROC ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 

int n,r,c;
int cnt = 0;
bool found = false;

void func(int y, int x, int depth){
    if (found) return; // flag
    if(depth == 0){
        if (y==r && x==c) {
            found = true;
            return;
        }
        cnt++;
        // cout << "(Y,X)" << y << ',' << x << endl;
        return;
    }
    
    int len = (1 << depth-1);
    int size = len * len;
    
    int dy[4] = {0,0,1,1};
    int dx[4] = {0,1,0,1};
    for(int k=0; k<4; k++){
        int ny = y + (len * dy[k]);
        int nx = x + (len * dx[k]);
        if(r>=ny && r<ny+len && c>=nx && c<nx+len) {
            // cout << "cnt:" << cnt << ", (ny, nx, len):" << ny << ", " << nx << ',' << len << endl;
            func(ny, nx, depth-1);
            if(found) return;
        }
        cnt += size;
    }
}

int main(void){
    PRE_PROC
    cin >> n >> r >> c;
    func(0,0,n);
    cout << cnt << endl;
    return 0;
}