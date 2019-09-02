#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
const int N = 100005;

struct edge {
  int u, v;
  edge(int _u, int _v) {
    if (_u < _v) {
      u = _u;
      v = _v;
    } else {
      u = _v;
      v = _u;
    }
  }
  bool operator<(const edge &p) const {
    if (u == p.u)
      return v < p.v;
    else
      return u < p.u;
  }
};

vector<int> adj[N];
bool vis[N];
vector<edge> bridges;
int dis[N], low[N];
int tick, numBridge;

void dfs(int u, int p) {
  vis[u] = true;
  dis[u] = low[u] = ++tick;
  int child = 0;

  for (int i = 0; i < adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == p) continue;
    // cout << u << " -> " << v << endl;
    if (vis[v]) {
      // backedge
      low[u] = min(dis[v], low[u]);
    }
    if (!vis[v]) {
      dfs(v, u);
      low[u] = min(low[u], low[v]);
      child++;

      if (dis[u] < low[v]) {
        bridges.push_back(edge(u, v));
        numBridge++;
      }
    }
  }
}

void dfs_init(int n) {
  memset(dis, 0, sizeof(dis));
  memset(vis, false, sizeof(vis));
  memset(low, 0, sizeof(low));
  tick = 0;
  numBridge = 0;
  // cout << "dfs init called\n";
  for (int i = 0; i < n; i++) {
    if (!vis[i]) dfs(i, -1);
  }
  sort(bridges.begin(), bridges.end());
}

int main() {
  int n, e;
  scanf("%d %d", &n, &e);
  for (int i = 0; i < e; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs_init(n);
  //  for (int i = 0; i<n; i++) cout << i << " dis : " << dis[i] << " low : " <<
  //  low[i] << endl;;
  if (numBridge) {
    for (int i = 0; i < bridges.size(); i++) {
      cout << bridges[i].u << " " << bridges[i].v << endl;
    }
  }
  return 0;
}