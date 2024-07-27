/**
 * name:    
 * solved:  N
 */

#include<iostream>
#include<string>
#include<list>
#include<algorithm>
#define PRE_PROC ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
using namespace std;

void run(){
    /* code HERE */
    int i, n, x;
    char ch;
    string s;

    cin >> n;
    while (n--) {
        cin >> s;
        list<char> l;
        list<char>::iterator cursor = l.begin();
        for (i=0; i<s.size(); i++) {
            if (s[i] == '>') {                   // move right
                if (cursor != l.end()) {
                    cursor++;
                }
            } else if (s[i] == '<') {            // move left
                if (cursor != l.begin()) {
                    cursor--;
                }
            } else if (s[i] == '-') {            // backspace(-)
                if (cursor != l.begin()) {
                    cursor--;
                    cursor = l.erase(cursor);
                }
            } else {                             // insert other characters prior to cursor
                l.insert(cursor, s[i]);
            }
        }
        for (const auto& a : l) {
            cout << a;
        }
        cout << '\n';
    }
    
}
int main(void){
    PRE_PROC
    run();
    return 0;
}