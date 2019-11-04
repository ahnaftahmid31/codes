#include<bits/stdc++.h>
using namespace std;

#define  white 0
#define  red 1
#define  blue 2
#define  N 103
#define  pii pair<int, int>

int adj[N][N];
bool vis[N][N];
int level[N][N];
int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};

int bfs(int sx, int sy, int row, int col)
{
  if(adj[sx][sy] == -1){
    return -1;
  }

  level[sx][sy] = 0;
  vis[sx][sy] = true;
  queue<pii> q;
  q.push(pii(sx, sy));

  while(!q.empty())
  {
    pii u = q.front();
    int ux = u.first;
    int uy = u.second;
    q.pop();

    for(int i = 0; i<4; i++)
    {
      int vx = ux + fx[i];
      int vy = uy + fy[i];

      if(vx < col && vx >= 0 && vy < row && vy >= 0){
        if(!vis[vx][vy]){
          vis[vx][vy] = true;

          if(adj[vx][vy] == -1) continue;
          else{
            level[vx][vy] = level[ux][uy] + 1;
            if(vx == col-1 && vy == row-1){
              return level[vx][vy];
            }
            q.push(pii(vx, vy));
          }
        }
      }
    }
  }
  return -1;
}

void clearAll(int r, int c){
  for(int i = 0; i<=r; i++){
    for(int j = 0; j<=c; j++){
      adj[j][i] = 0;
      level[j][i] = 0;
      vis[j][i] = false;
    }
  }
}



int main(){

  int row, col;
  scanf("%d %d", &row, &col);

  clearAll(row, col);

  for(int i = 0; i<row; i++){
    string str;
    cin >> str;
    for(int j = 0; j<col; j++){

      if(str[j] == '.'){
        adj[j][i] = 1;
      }
      if(str[j] == '#'){
        adj[j][i] = -1;
      }
    }
  }

  int res = bfs(0, 0, row, col);
  cout << res << endl;
}

