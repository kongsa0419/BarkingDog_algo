/**
 * name:    
 * solved:  N
 */

#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<algorithm>
#define PRE_PROC ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
using namespace std;

void run(){
    /* code HERE */
    /**
     * if (stack.top() < v[i]) : stack.push() until v[i]
     * else if (stack.top() == v[i]) : stack.pop() & continue;
     * else : cannot make permutation(순열)
     */

    int n, i, j, x;
    bool status = true;
    vector<int> v;
    vector<char> ret;
    stack<int> s;

    cin >> n;
    v.reserve(n);               //  capacity (n)
    ret.reserve(2 * n + 5);
    for (i=0; i<n; i++) {
        cin >> v[i];            // original input (permutation)
    }

    //  main
    i = 0;  // permutation index
    j = 1;  // stack.top()
    do {
        while (j <= n && i < n && j <= v[i]) {
            s.push(j++);
            ret.push_back('+');
        }
        if (!s.empty() && i < n && s.top() > v[i]) {
            status = false;  // error
            break;
        } else if (!s.empty() && i < n && s.top() == v[i]) {
            while (!s.empty() && i < n && s.top() == v[i]) {
                s.pop();
                ret.push_back('-');
                i++;
            }
            if (j > n && i == n) {
                break; // successfuly end
            }
        }
        
        if (i >= n || j > n) {
            status = false;  //  error
        }
    } while (status);

    if (status) {
        for (const auto& ch : ret) {
            cout << ch << '\n';
        }
    } else { 
        cout << "NO\n";
    }

    return;
}


int main(void){
    PRE_PROC
    run();
    return 0;
}