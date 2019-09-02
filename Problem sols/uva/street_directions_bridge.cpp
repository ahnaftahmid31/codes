#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
const int N = 100005;

struct edge {
  int u, v;
  edge(int _u, int _v) : u(_u), v(_v) {}
  bool operator < (const edge &p) const{
    if ( u == p.u) return v < p.v;
    return u < p.u;
  }
};

vector<int> adj[N], rev[N];
int dis[N], low[N], tick;
bool vis[N];
set<edge> edges;
map<edge,bool> used;

void dfs(int u, int p) {
  dis[u] = low[u] = ++tick;
  vis[u] = true;
  int child = 0;
  for (int i = 0; i < adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == p) continue;
    if(!used[{u, v}]){
      edges.insert({u, v});
      used[{u, v}] = true;
      used[{v, u}] = true;
    }
    if (vis[v]) low[u] = min(low[u], dis[v]);
    else {
      dfs(v, u);
      child++;
      low[u] = min(low[u], low[v]);
      if (dis[u] < low[v]) {
        edges.insert({v, u});
      }
    }
  }
}

int main() {
  int n, e, caseno = 0;
  while (scanf("%d %d", &n, &e) == 2 && n + e) {

    for (int i = 0; i<=n; i++) adj[i].clear();
    memset(vis, false, sizeof(vis));
    memset(dis, 0, sizeof(dis));
    memset(low, 0, sizeof(low));
    edges.clear();
    used.clear();

    for (int i = 0; i < e; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      adj[u].push_back(v);
      adj[v].push_back(u);
      used[{u, v}] = false;
      used[{v, u}] = false;
    }

    for (int i = 1; i <= n; i++) {
      if (!vis[i]) dfs(i, -1);
    }
    
    printf("%d\n\n", ++caseno);
    set<edge>::iterator it;
    for (it = edges.begin(); it != edges.end(); it++) {
      cout << it->u << " " << it->v << endl;
    }
    printf("#\n");
  }
}