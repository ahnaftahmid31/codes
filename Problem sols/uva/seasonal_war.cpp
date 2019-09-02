#include<bits/stdc++.h>
using namespace std;

#define N 102
#define pii pair<int, int>

int adj[N][N];
bool vis[N][N];
int numEagle;
//direction array assuming graph is |-->
//                                  V
int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};

void reset(int dim) {
  numEagle = 0;

  for(int i = 0; i<dim; i++) {
    for(int j = 0; j<dim; j++) {
      adj[i][j] = -1;
      vis[i][j] = false;
    }
  }
}

void bfs(int r, int c, int dim) {
  queue<pii> q;
  q.push(pii(r, c));

  while(!q.empty()) {
    pii top = q.front();
    q.pop();
    int y = top.first;  // row corresponds to y-axis
    int x = top.second; // column corresponds to x-axis

    for(int i = 0; i<8; i++) {
      int tx = x + dx[i];
      int ty = y + dy[i];

      if(tx >= 0 && ty >= 0 && tx < dim && ty < dim ) {
        // column -> x, row -> y and our array is in arr[row][col] format
        if(!vis[ty][tx]) {
          vis[ty][tx] = true;

          if(adj[ty][tx] == 1){
            q.push(pii(ty, tx));
          }
        }
      }
    }
  }
}

void find_eagle(int dim) {

  for(int i = 0; i<dim; i++) {
    for(int j = 0; j<dim; j++) {

      if(!vis[i][j]) {
        vis[i][j] = true;

        if(adj[i][j] == 1) {
          bfs(i, j, dim);
          numEagle ++;
        }
      }
    }
  }
}

int main() {

  int dim; //dimension
  int image_no = 0;

  while(cin >> dim){
    reset(dim);

    for(int i = 0; i<dim; i++) {
      char str[35];
      scanf("%s", str);
      for(int j = 0; j<dim; j++) {
        int u = str[j] - '0';
        adj[i][j] = u;
      }
    }

    find_eagle(dim);
    image_no++;
    printf("Image number %d contains %d war eagles.\n", image_no, numEagle);
  }
}
