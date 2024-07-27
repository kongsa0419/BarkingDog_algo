/**
 * name:    
 * solved:  N
 */

#include<iostream>
#include<string>
#include<algorithm>
#define PRE_PROC ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
using namespace std;

void run(){
    /* code HERE */
    string s1, s2;
    string res[2] = {"Impossible", "Possible"}; // 0(imp) , 1(pos)
    int n, i, flag;
    int cnt[26]; // lower case

    cin >> n;
    while (n--) {
        flag = 1; // true
        fill(cnt, cnt + 26, 0); // init
        // main logic
        cin >> s1 >> s2;
        for (i=0; i<s1.size(); i++) {
            cnt[s1[i]-'a']++;
        }
        for (i=0; i<s2.size(); i++) {
            cnt[s2[i]-'a']--;
        }

        for (i=0; i<26; i++) {
            if (cnt[i] != 0) {
                flag = 0;
                cout << res[0] << '\n';
                break;
            }
        }
        if (flag) {
            cout << res[1] << '\n';
        }
    }
}
int main(void){
    PRE_PROC
    run();
    return 0;
}