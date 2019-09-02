#include <bits/stdc++.h>
using namespace std;

#define white 0
#define red 1
#define blue 2
#define maxNodes 100005

vector<int> edgeof[maxNodes];
int color[maxNodes];
int level[maxNodes];

bool bfs(int source) {
  // no recursive call xD
  color[source] = red;
  queue<int> q;
  q.push(source);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = 0; i < edgeof[u].size(); i++) {
      int v = edgeof[u][i];

      if (color[v] == white) {
        // printf("  %d --> %d\n", u, v);
        if (color[u] == red)
          color[v] = blue;
        else
          color[v] = red;
        q.push(v);
      } else if (color[u] == color[v]) {
        // return if the graph is bi-colorable
        return false;
      }
    }
  }
  return true;
}

void clearAll(int numNodes) {
  for (int i = 0; i <= numNodes; i++) {
    edgeof[i].clear();
    color[i] = white;
    level[i] = 0;
  }
}

int main() {
  int numVertex, numEdges;
  scanf("%d %d", &numVertex, &numEdges);
  clearAll(numVertex);
  for (int i = 0; i < numEdges; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    edgeof[u].push_back(v);
    edgeof[v].push_back(u);
  }
  if (bfs(1))
    printf("bi-colorable\n");
  else
    printf("not bi-colorable\n");
}

/*
8 11
1 4
1 5
1 6
4 5
4 3
4 2
2 3
4 7
7 5
5 6
7 8
*/
