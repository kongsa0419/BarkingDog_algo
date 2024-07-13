#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#define PRE_PROC ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
using namespace std;

void run(){
    /* code HERE */
    int n, i, j;
    bool status = true;
    vector<int> v;
    queue<char> ret;

    cin >> n;
    v.reserve(n+1);
    for (i=1; i<=n; i++) {
        cin >> v[i];
    }
    stack<int> s;
    j = i = 1;
    while (i<=n && j<=n) {
        while (j <= v[i]) {
            s.push(j++);
            ret.push('+');
        }
        while (!s.empty() && s.top() == v[i]) {
            s.pop();
            ret.push('-');
            i++;
        }
        if (!s.empty() && s.top() > v[i]) {
            status = false;
            break;
        }
    }

    if (status) {
        // print
        while (!ret.empty()) {
            cout << ret.front() << '\n';
            ret.pop();
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