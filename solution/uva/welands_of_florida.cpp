#include<bits/stdc++.h>
using namespace std;

#define N 102
#define pii pair<int, int>

char adj[N][N];
bool vis[N][N];
int rows, cols;
int area;
//direction array assuming graph is |-->
//                                  V
int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};

void reset(int dim) {
  area = 0;
  rows = 0;
  cols = 0;

  for(int i = 0; i<dim; i++) {
    for(int j = 0; j<dim; j++) {
      adj[i][j] = '\0';
      vis[i][j] = false;
    }
  }
}
void reset_vis() {
  for(int i = 0 ; i<=rows; i++)
    for(int j = 0; j<=cols; j++)
       vis[i][j] = false;
  area = 0;
}

void dfs (int r, int c) {
  if(r >= 0 && c >= 0 && r < rows && c < cols) {
    if(!vis[r][c] && adj[r][c] == 'W') {
      area++;
      vis[r][c] = true;
      for(int i = 0; i < 8; i++) {
        dfs(r + dy[i], c + dx[i]);
      }
    }
  }
}

void printGraph() {
  for(int i = 0; i<rows; i++) {
    printf("%s\n", adj[i]);
  }
}

int main() {
  int cases;
  char str[102];
  scanf("%d ", &cases);
  while(cases--){
    reset(100);
    int row = 0;

    while(gets(str)) {
      if(str[0] == '\0') {
         break;
      }
      else if(str[0] != 'W' && str[0] != 'L') {
        int r, c;
        sscanf (str, "%d %d", &r, &c);
        rows = row;
        cols = strlen(adj[row - 1]);
        reset_vis();
        dfs(r - 1, c - 1);
        int lake_size = area;
        printf("%d\n", lake_size);
        reset_vis();
      }
      else {
        sscanf(str, "%s", adj[row]);
        row++;
      }
    }
    if(cases) puts("");
  }
}
