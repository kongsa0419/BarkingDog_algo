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

bool func(int idx, vector<string>& book, int n){
    vector<string> nbook[10]; // radix
    // fatal algorithm
    for(int i=0; i<book.size(); i++){
        if(book[i].size() > idx && )
        nbook[book[i][idx]].push_back();
    }
}
bool solution(vector<string> phone_book) {
    bool answer = true;
    int n = phone_book.size();
    answer = func(0, phone_book);
    return answer;
}

int main(void){
    PRE_PROC
    vector<string> v;
    string x;
    while(1){
        cin >> x;
        if(x=="0") break;
        v.push_back(x);
    }
    if(solution(v)) cout << "TRUE\n";
    else cout << "FALSE\n";
    return 0;
}