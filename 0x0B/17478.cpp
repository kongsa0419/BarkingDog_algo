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

#define PRE_PROC ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
using namespace std;
void func(const int& n, const int& i) {
    int cnt;

    cnt = i;
    while(cnt--) cout << "____";
    cout << "\"재귀함수가 뭔가요?\"\n";
    if(n==i){
        // base condition
        cnt = i;
        while(cnt--) cout << "____";
        cout << "\"재귀함수는 자기 자신을 호출하는 함수라네\"\n";
        cnt = i;
        while(cnt--) cout << "____";
        cout << "라고 답변하였지.\n";
        return;
    }
    cnt = i;
    while(cnt--) cout << "____";
    cout << "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n";
    cnt = i;
    while(cnt--) cout << "____";
    cout << "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n";
    cnt = i;
    while(cnt--) cout << "____";
    cout << "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n";

    func(n, i+1);

    cnt = i;
    while(cnt--) cout << "____";
    cout << "라고 답변하였지.\n";
}
int main(void){
    PRE_PROC
    int n, i;
    cin >> n;
    i = 0;
    cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";
    func(n, i);
    return 0;
}