/**
 * name:    
 * solved:  N
 */

#include<iostream>
#include<string>
#include<list> // linked list, queue
#include<vector>
#include<algorithm>
#define PRE_PROC ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
using namespace std;

void run(){
    /* code HERE */
    int n, k, i, x;
    cin >> n >> k;
    list<int> q; // 순열 (permutation0
    vector<int> v;
    v.reserve(n); // vector capacity만 미리 잡아 두기

    for (i=1; i<=n; i++) {
        q.push_back(i);
    }
    
    i = 0; // count
    while (!q.empty()) {
        x = q.front();
        q.pop_front();
        if (++i == k) {
            i = 0;
            v.emplace_back(x);
            continue;
        }
        q.push_back(x);
    }

    cout << "<";
    for (i=0; i<v.size(); i++) {
        cout << v[i];
        if (i == v.size() - 1) {
            break;
        }
        cout << ", ";
    }
    cout << ">";
    // while(1) {
    //     cout << ret.front();
    //     ret.pop_front();
    //     if (!ret.empty()) {
    //         cout << ", ";
    //     } else {
    //         break;
    //     }
    // }
    // cout << ">";
}

int main(void){
    PRE_PROC
    run();
    return 0;
}