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
    int cnt[26] = {0, };  // lower-cased
    int i, x;

    cin >> s1 >> s2;
    for (i=0; i<s1.size(); i++) {
        cnt[s1[i]-'a']++;
    }
    for (i=0; i<s2.size(); i++) {
        cnt[s2[i]-'a']--;
    }

    x = 0;
    for (i=0; i<26; i++) {
        if (cnt[i] > 0) {
            x += cnt[i];
        }else if (cnt[i] < 0) {
            x -= cnt[i];
        }
    }
    cout << x << '\n';
}
int main(void){
    PRE_PROC
    run();
    return 0;
}