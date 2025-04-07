/*
1. Stack에 '{'를 push할 때는 별다른 조건이 필요없다를
2. 대신 '}'를 push 할때는 스택 empty()여부를 확인해야한다. stack.top()이 '{'이면
    pop()하고, 그렇지 않으면 top()을 '{'가 되도록 바꿔줘야함.
3. 이렇게 하다보면 마지막에 Stack에 남는 경우가 생긴다.
    TestCase) ['{', '{', '{', '}',]
    for문 이후에 이 경우를 처리해준다.
*/
#include <iostream>
#include <stack>
using namespace std;

// line을 안정적으로 바꾸는 데에 필요한 최소 연산의 수를 return
int play(string line) {
  int mn = 0;
  stack<int> S;
  for (int i = 0; i < line.size(); i++) {
    if (line[i] == '{')
      S.push('{');
    else if (S.empty()) {
      ++mn;
      S.push('{');
    } else {
      if (!S.empty() && S.top() == '}') {
        ++mn;
      }
      S.pop();
    }
  }

  if (!S.empty()) {
    int k = (S.size() / 2);
    mn += k;
  }
  return mn;
}

int main(void) {
  string line;
  int tc = 1;
  while (true) {
    cin >> line;
    if (line[0] == '-')
      break;  // 종료 조건
    else
      cout << tc++ << ". " << play(line) << '\n';
  }
  return 0;
}