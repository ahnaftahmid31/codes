#include<bits/stdc++.h>
using namespace std;

#define N 102

int rows, cols, deposits = 0;
char adj[N][N];
bool vis[N][N];
//direction array assuming graph is |-->
//                                  V
int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};


void dfs(int r, int c) {
  if(r >= 0 && c >= 0 && r < rows && c < cols) {
    if(!vis[r][c] && adj[r][c] == '@') {
      //
      vis[r][c] = true;
      for(int i = 0; i < 8; i++) {
        dfs(r + dy[i], c + dx[i]);
      }
    }
  }
}

void find_deposit() {
  deposits = 0;
  for(int r = 0; r < rows; r++) {
    for(int c = 0; c < cols; c++) {
      if(!vis[r][c]) {
        if(adj[r][c] == '@') {
          dfs(r, c);
          deposits++;
        }
      }
    }
  }
}
void reset(int r, int c) {
  for(int i = 0; i<rows; i++) {
    for(int j = 0; j<cols; j++) {
      adj[i][j] = '\0';
      vis[i][j] = false;
    }
  }
}

int main() {
  while(true) {
    scanf("%d %d", &rows, &cols);
    if(rows == 0) break;
    reset(rows, cols);

    string str;
    for(int r = 0; r < rows; r++) {
      cin >> str;
      for(int c = 0; c < cols; c++) {
        adj[r][c] = str[c];
      }
    }
    find_deposit();
    cout << deposits << endl;
  }
}
