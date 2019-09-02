#include <bits/stdc++.h>
using namespace std;

#define white 0
#define grey 1
#define black 2
#define maxNodes 100005

vector<int> reverseG[maxNodes];
vector<int> edgeof[maxNodes];
vector<int> components[maxNodes];
stack<int> stk;
int numComp;
int color[maxNodes];
bool isVisited[maxNodes];

void dfs(int u) {
  color[u] = grey;

  for (int i = 0; i < edgeof[u].size(); i++) {
    int v = edgeof[u][i];
    if (color[v] == white) {
      dfs(v);
    }
  }

  color[u] = black;
  stk.push(u);
}

void dfs2(int u) {
  components[numComp].push_back(u);
  isVisited[u] = true;
  for (int i = 0; i < reverseG[u].size(); i++) {
    int v = reverseG[u][i];
    if (!isVisited[v]) {
      dfs2(v);
    }
  }
}

void dfs_init(int numVer) {
  for (int i = 0; i <= numVer; i++) {
    color[i] = white;
    isVisited[i] = false;
    components[i].clear();
  }
  numComp = 0;

  for (int i = 0; i < numVer; i++) {
    if (color[i] == white) {
      dfs(i);
    }
  }
  while (!stk.empty()) {
    int u = stk.top();
    stk.pop();
    if (!isVisited[u]) {
      numComp++;
      dfs2(u);
    }
  }
}

void printComponents() {
  int i, j;
  for (i = 1; i <= numComp; i++) {
    for (j = 0; j < components[i].size() - 1; j++) {
      cout << components[i][j] << " ";
    }
    cout << components[i][j];
    cout << "\n";
  }
}

int main() {
  int numVertex, numEdges;
  scanf("%d %d", &numVertex, &numEdges);

  for (int i = 0; i <= numVertex; i++) {
    edgeof[i].clear();
    reverseG[i].clear();
  }

  for (int i = 0; i < numEdges; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    edgeof[u].push_back(v);
    reverseG[v].push_back(u);
  }

  dfs_init(numVertex);
  printComponents();
}
