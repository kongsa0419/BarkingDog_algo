#include <bits/stdc++.h>
using namespace std;

char board[2300][2300];

void solve(int n, int x, int y) {
  if (n == 1) {
    board[x][y] = '*';
    return;
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (i == 1 && j == 1)
        continue;
      solve(n / 3, x + n / 3 * i, y + n / 3 * j);
    }
  }
}

int main(void) {
    vector<vector<char>> map(3, vector<char>());
    int n=3;
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n+1;j++){
            cout << map[i][j];
        }
        cout << '\n';
    }
}