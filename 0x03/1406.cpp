/**
 * name:    
 * solved:  N
 */

#include<iostream>
#include<string>
#include<algorithm>
#include<list> // linked list
#define PRE_PROC ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
using namespace std;

void run(){
    /* code HERE */
    string s;
    int i, n, x;
    char cmd, opt; 
    
    cin >> s;
    list<char> memo (s.begin(), s.end());
    list<char>::iterator it = memo.end();
    

    // for (i=0; i<s.size(); i++) {
    //     memo.emplace_back(s.at(i));
    // }

    it = memo.end();
    cin >> n;
    for (i=0; i<n; i++) {
        cin >> cmd;
        if (cmd == 'P') {
            /* opt 문자를 커서 왼쪽에 추가함 */
            cin >> opt;
            memo.insert(it, opt);
        } else {
            switch (cmd) {
                case 'L': /* 커서를 왼쪽으로 한 칸 옮김 (커서가 문장의 맨 앞이면 무시됨) */
                {
                    if (it != memo.begin()) {
                        it--;
                    }
                    break;
                }
                case 'D': /* 커서를 오른쪽으로 한 칸 옮김 (커서가 문장의 맨 뒤이면 무시됨) */
                {
                    if (it != memo.end()) {
                        it++;
                    }
                    break;
                }
                case 'B': 
                {
                    /*
                        커서 왼쪽에 있는 문자를 삭제함 (커서가 문장의 맨 앞이면 무시됨).
                        삭제로 인해 커서는 한 칸 왼쪽으로 이동한 것처럼 나타나지만, 실제로 커서의 오른쪽에 있던 문자는 그대로임
                    */
                   if (it != memo.begin()) {
                        it--;
                        it = memo.erase(it);
                   }
                    break;
                }
            }
        }
    }

    // print memo
    it = memo.begin();
    while (it != memo.end()) {
        cout << *it++;
    }
    cout << '\n';
}
int main(void){
    PRE_PROC
    run();
    return 0;
}