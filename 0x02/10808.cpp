/**
 * name:    
 * solved:  N
 */

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#define PRE_PROC ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
using namespace std;

void run(){
    /* code HERE */
    int cnt[26] = {0,};
    // 65~90(CAPITAL), 97~112
    string in;
    cin >> in;
    for(int i=0; i<in.size(); i++){
        cnt[in[i]-'a']++;
    }
    for(int i=0; i<26; i++){
        cout << cnt[i] << ' ';
    }
    return;
}
int main(void){
    PRE_PROC
    run();
    return 0;
}