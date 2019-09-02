#include <bits/stdc++.h>
using namespace std;

vector<int> edgeOf[100005];
bool res = false;

void dfs(int source, string color[]) {
  int u = source;
  color[u] = "grey";
  for (int i = 0; i < edgeOf[u].size(); i++) {
    int v = edgeOf[u][i];
    if (color[v] == "black") {
      res = true;
      break;
    }
    if (color[v] == "white") {
      dfs(v, color);
    }
  }
  color[u] = "black";
}

void dfs_init(int numVertex, int numEdges) {
  string color[numVertex];
  for (int i = 0; i < numVertex; i++) {
    color[i] = "white";
  }
  for (int i = 0; i < numVertex; i++) {
    if (color[i] == "white") {
      dfs(i, color);
    }
  }
}

int main() {
  int numVertex;
  int numEdges;

  scanf("%d %d", &numVertex, &numEdges);
  for (int i = 1; i <= numEdges; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    edgeOf[u].push_back(v);
    edgeOf[v].push_back(u);
  }
  dfs_init(numVertex, numEdges);
  if (res)
    printf("Yes\n");
  else
    printf("No\n");
}
