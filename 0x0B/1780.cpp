/**
 * name:    
 * solved:  N
 * 1) 입력을 받는다.
 * 2) func 호출:
 *      parameter: int& g1, g2, g3
 *      + const int y, x , len
 *   * 함수가 하는일: y,x를 len/3으로 나눠서 총 9등분하여 재귀적 함수 호출
 *  만약 해당 부위가 채워져있는지 체크 (Base Condition), 그렇다면 더이상 재귀 x + g(1,2,3)에 count
 * 
 * ## 다듬기 ##
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


void func(const vector<vector<int>>& map, int& g1, int& g2, int& g3, const int& y, const int& x, const int& n)
{
    // cout << "dbg) [g1,g2,g3,y,x,n]:" << g1 << ',' << g2 << ',' << g3 << ',' << y << ',' << x << ',' << n << "]\n";
    // Base condition
    if(n==1) {
        if(map[y][x] == -1) g1++;
        else if (map[y][x]== 0) g2++;
        else g3++;
        return;
    }

    //check paper
    int pn = n/3;
    bool paper = true;
    int pre = map[y][x];
    int i,j;
    for(i=y; i<y+n && paper; i++){
        for(j=x; j<x+n && paper; j++){
            if(pre != map[i][j]) paper = false;
        }
    }

    if(paper) {
        if(map[y][x] == -1) g1++;
        else if (map[y][x]== 0) g2++;
        else g3++;
        return;
    }
    int d[3]={0,1,2};
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            func(map, g1, g2, g3, y + pn*d[i], x + pn*d[j], pn);
        }
    }
}


void dbg(vector<vector<int>>& map, int n){
    int i,j;
    cout<<"DBG)\n";
    for(i=0; i<n; i++){
        for(j=0;j<n;j++){
            cout<<map[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(void){
    PRE_PROC
    int n, i, j;
    // int** map;
    int g1,g2,g3; // -1, 0, 1
    g1=g2=g3=0;

    cin >> n;
    vector<vector<int>> map(n);
    for(i=0; i<n; i++){
        // map+i = new int[n+3];
        map[i].reserve(n);
        for(j=0;j<n;j++){
            cin >> map[i][j];
        }
    }
    /*
    for(i=0; i<n+3; i++){
        for(j=0; j<n+3; j++){
            cin >> map[i][j];
        }
    }
    */
    // dbg(map, n);
    func(map, g1, g2, g3, 0, 0, n);
    cout  << g1 << '\n' << g2 << '\n' << g3 << '\n';
    return 0;
}