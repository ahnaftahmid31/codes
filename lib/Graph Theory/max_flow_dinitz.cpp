#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
const int inf = 1 << 30;

struct edge {
  int u, v, res_cap;
  edge(int _u, int _v, int _cap) : u(_u), v(_v), res_cap(_cap) {}
};

vector<int> adj[N];
vector<edge> edges;
int level[N], max_flow;

bool bfs(int s, int t) {
  memset(level, -1, sizeof(level));
  level[s] = 0;
  queue<int> q;
  q.push(s);
  cout << "bfs called\n";

  while (!q.empty()) {
    int u = q.front(); q.pop();

    for (int i = 0; i < adj[u].size(); i++) {
      int v = edges[adj[u][i]].v;  // adj[u][i] returns a id for u --> v edge
      int cap = edges[adj[u][i]].res_cap;

      if (cap && level[v] == -1) {
        level[v] = level[u] + 1;
        if (v == t) return true;
        q.push(v);
      }
    }
  }
  return false;
}

int dfs(int u, int t, int flow) {  // u = source but it will update
  if (u == t) return flow;
  if(flow == 0) return 0;

  for (int i = 0; i < adj[u].size(); i++) {
    int id_uv = adj[u][i];  // adj[u][i] --> id for u -> v
    int id_vu = id_uv + 1;
    int v = edges[id_uv].v;
    int cap = edges[id_uv].res_cap;

    if (level[v] == level[u] + 1 && cap) {
      flow = min(flow, cap);
      
      int new_flow = dfs(v, t, flow);
      if (new_flow) {
        edges[id_uv].res_cap -= new_flow;
        edges[id_vu].res_cap += new_flow;
        //cout << u << " -> " << v << " flowing: " << new_flow << endl;
        return new_flow;
      }
    }
  }
  return 0;
}

void dinic(int s, int t) {
  max_flow = 0;

  while (bfs(s, t)) {
    while (int new_flow = dfs(s, t, inf)) {
      cout << "returned flow: " << new_flow << endl;
      max_flow += new_flow;
    }
  }
}

int main() {
  int n, e;
  scanf("%d %d", &n, &e);
  int s, t;
  scanf("%d %d", &s, &t);

  int id = 0;
  for (int i = 0; i < e; i++) {
    int u, v, cap;
    scanf("%d %d %d", &u, &v, &cap);   
    edges.push_back(edge(u, v, cap));
    edges.push_back(edge(v, u, 0));
    adj[u].push_back(id++);  // storing edges in a way that
    adj[v].push_back(id++);  // id(v -> u) = 1 + id(u -> v)
  }
  dinic(s, t);
  cout << "total flow: " << max_flow << endl;
}