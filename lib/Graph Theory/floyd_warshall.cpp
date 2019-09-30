#include<bits/stdc++.h>
using namespace std;

const int N = 1003;
const int inf = INT_MAX /2;

int cost[N][N];
int adj[N][N];
int nxt[N][N];

void reset(int n) {
  for (int i = 0; i<=n; i++) {
    for (int j = 0; j<=n; j++) {
      nxt[i][j] = j;
      cost[i][j] = inf;
      if (i == j) cost[i][i] = 0;
    }
  }
}

void fowarshall(int n) {
  for (int k = 1; k<=n; k++) {
    for (int i = 1; i<=n; i++) {
      for (int j = 1; j<=n; j++) {
        if (cost[i][k] + cost[k][j] < cost[i][j]){
          cost[i][j] = cost[i][k] + cost[k][j];
          nxt[i][j] = nxt[i][k];
        } 
      }
    }
  }
}

vector<int> path;

void path_find(int i, int j) {
  cout << cost[i][j] << endl;
  if (cost[i][j] == inf) printf("No path\n");
  path.clear();
  path.push_back(i);
  printf("%d" , i);
  int x = i;
  while(x != j) {
    x = nxt[x][j];
    printf(" -> %d " , x);
    path.push_back(x);
  }
}
 
int main() {
  int cases;
  cin >> cases;
  while(cases--) {
    int n, e;
    cin >> n >> e;
    reset(n);
    for (int i = 0; i<e; i++) {
      int u, v, w;
      cin >> u >> v >> w;
      cost[u][v] = w;
    }
    fowarshall(n);
    printf("fowarshal done!\n");
    path_find(1, 4);
    //cout << path.size() << endl;
  }
}