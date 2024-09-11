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

struct cmp
{
    bool operator() (const pair<int,int>& p1, const pair<int,int>& p2)
    {
        if(p1.first == p2.first){
            return (p1.second > p2.second);
        }
        return (p1.first > p2.first); // min-heap
    }
};

int main(void){
    PRE_PROC
    int n,l;
    int i,j,k,x;
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq; // min-heap
    cin >> n >> l;
    for(i=0; i<n; i++){
        cin >> x;
        pq.push({x,i});
        if(i < l-1) continue;
        if (!pq.empty()){
            int x,y;
            auto& a = pq.top();
            x=a.X; y=a.Y;
            while (i >= y && y >= i+1-l) {
                // y ~ i 까지 x로 출력
                cout << x << ' ';
                y++;
            }
            pq.pop();
        }
    }
    return 0;
}