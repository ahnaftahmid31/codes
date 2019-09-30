#include <bits/stdc++.h>
using namespace std;

#define dir 1
#define undir 2
#define N 100005
#define pb(x) push_back(x)

void make_dot(int type) {
  printf("Enter number of Nodes and Edges:\n");
  int n, e, start;
  vector<int> adj[N];

  scanf("%d %d", &n, &e);
  printf("Enter the edges:\n");
  for (int i = 0; i < e; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    if (u == 0 || v == 0) start = 0;
    adj[u].pb(v);
  }
  for (int i = 0; i <= n; i++) {
    if (start == 1 && i == 0) continue;
    if (start == 0 && i == n) continue;
    if (adj[i].size() == 0) printf("%d;\n", i);
    for (int j = 0; j < adj[i].size(); j++) {
      int u = i;
      int v = adj[i][j];
      if (type == dir) {
        printf("%d -> %d;\n", u, v);
      } else {
        printf("%d -- %d;\n", u, v);
      }
    }
  }
}

int main() {
  printf("Enter what kind of graph :\n(if directed type dir else undir)\n");
  string graph_type = "dir";
  cin >> graph_type;
  if (graph_type == "dir") {
    make_dot(dir);
  } else if (graph_type == "undir") {
    make_dot(undir);
  } else {
    printf("Please enter a valid value!(dir, undir)\n");
  }
}