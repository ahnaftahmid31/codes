#include <bits/stdc++.h>
using namespace std;

#define white 0
#define grey 1
#define black 2
#define maxNodes 100005

vector<int> edgeof[maxNodes];
vector<int> aps;
bool visited[maxNodes];
int dis[maxNodes];
int parent[maxNodes];
int low[maxNodes];
bool ap[maxNodes];
int t;  // <-- time

void dfs(int u, int p) {
  visited[u] = true;
  dis[u] = ++t;
  low[u] = dis[u];
  int numChild = 0;  // number of white, unvisited child

  for (int i = 0; i < edgeof[u].size(); i++) {
    int v = edgeof[u][i];

    if (v == p) continue;  // if parent then ignore

    if (visited[v]) {
      low[u] = min(low[u], dis[v]);  // back-edge
    }

    if (!visited[v]) {
      numChild++;
      dfs(v, u);
      low[u] = min(low[u], low[v]);

      if (dis[u] <= low[v] && p != -1) {
        ap[u] = true;
        aps.push_back(u);
      }
    }
  }
  if (numChild > 1 && p == -1) {
    ap[u] = true;
    aps.push_back(u);
  }
}

void dfs_init(int numVer) {
  t = 0;
  for (int i = 0; i <= numVer; i++) {
    visited[i] = false;
    ap[i] = false;
    low[i] = 0;
    dis[i] = 0;
  }
  for (int i = 1; i <= numVer; i++) {
    if (!visited[i]) {
      dfs(i, -1);
    }
  }
}

void printAPs() {
  cout << "Total articulation points: " << aps.size() << " they are: \n";
  for (int i = 0; i < aps.size(); i++) {
    cout << aps[i] << " ";
  }
  printf("\n");
}

void query() {
  int numQuery;
  scanf("%d", &numQuery);

  int queries[maxNodes];
  for (int i = 1; i <= numQuery; i++) {
    cin >> queries[i];
  }

  for (int i = 1; i <= numQuery; i++) {
    if (ap[queries[i]] == true) {
      printf("Satisfied %d\n", edgeof[queries[i]].size());
    } else {
      printf("Not Satisfied\n");
    }
  }
}

void printLow(int n) {
  for (int i = 1; i <= n; i++) {
    cout << i << "->" << low[i] << ", ";
  }
  printf("\n");
}

int main() {
  int numVertex, numEdges;
  scanf("%d %d", &numVertex, &numEdges);

  for (int i = 0; i < numVertex; i++) {
    edgeof[i].clear();
  }

  for (int i = 0; i < numEdges; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    edgeof[u].push_back(v);
    edgeof[v].push_back(u);
  }

  dfs_init(numVertex);
  query();
}
