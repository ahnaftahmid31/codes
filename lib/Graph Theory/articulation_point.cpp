#include <bits/stdc++.h>
using namespace std;

#define N 100005

vector<int> adj[N], aps;
bool vis[N];
int dis[N], par[N], low[N], t;  // t <- time;
bool ap[N];

void dfs(int u, int p) {
  vis[u] = true;
  low[u] = dis[u] = ++t;
  int numChild = 0;  // number of unvisited child

  for (int i = 0; i < adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == p) {
      continue;
    }  // if parent then ignore
    if (vis[v]) {
      if (low[u] > dis[v]) {
        printf("%d %d --> backedge\n", u, v);
        low[u] = dis[v];  // back-edge
      }
    } else {
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

void dfs_init(int numVer, int s) {
  t = 0;
  for (int i = 0; i <= numVer; i++) {
    vis[i] = false;
    ap[i] = false;
    low[i] = 0;
    dis[i] = 0;
  }
  for (int i = s; i < numVer + s; i++) {
    if (!vis[i]) {
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

// a problem on hackerearth was solved using this
void query() {
  int numQuery, queries[N];
  scanf("%d", &numQuery);

  for (int i = 1; i <= numQuery; i++) {
    cin >> queries[i];
  }
  for (int i = 1; i <= numQuery; i++) {
    if (ap[queries[i]] == true) {
      printf("Satisfied %d\n", adj[queries[i]].size());
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
    adj[i].clear();
  }

  for (int i = 0; i < numEdges; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs_init(numVertex, 0);  // nodes, starting point
  printAPs();
}
