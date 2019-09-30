#include <bits/stdc++.h>  //complexity O(VE^2)
using namespace std;

#define N 1003
#define inf 1 << 30

vector<int> adj[N];
int res_cap[N][N];  // TODO : <-- integrate this into adj using struct
vector<int> par(N);
int cur_flow;

int bfs(int s, int t) {
  fill(par.begin(), par.end(), -1);
  par[s] = -2;  // path is saved each time bfs is called in this parent array
  queue<pair<int, int> > q;
  q.push({inf, s});

  while (!q.empty()) {
    int u = q.front().second;
    int flow = q.front().first;
    q.pop();

    for (int i = 0; i < adj[u].size(); i++) {
      int v = adj[u][i];
      int cap_v = res_cap[u][v];

      if (par[v] == -1 && cap_v) {
        par[v] = u;
        int new_flow = min(flow, cap_v);
        if (v == t) return new_flow;
        q.push({new_flow, v});
      }
    }
  }
  return 0;
}

// if there are multiple sources and sinks we will add
// a dummy source and a sink to make it a usual max_flow graph
int max_flow(int s, int t) {
  cur_flow = 0;
  int flow;

  while (flow = bfs(s, t)) {  // return a flow until there is no path left
    cout << "new flow: " << flow << endl;
    cur_flow += flow;
    int v = t;

    while (v != s) {
      int u = par[v];
      cout << u << " -> " << v << endl;
      res_cap[u][v] -= flow;
      res_cap[v][u] += flow;
      v = u;
    }
  }
  return cur_flow;
}

int main() {
  int n, e;
  scanf("%d %d", &n, &e);
  int s, t;
  scanf("%d %d", &s, &t);

  for (int i = 0; i < e; i++) {
    int u, v, cap;
    scanf("%d %d %d", &u, &v, &cap);
    adj[u].push_back(v);
    adj[v].push_back(u);
    res_cap[u][v] = cap;
    res_cap[v][u] = 0;
  }
  max_flow(s, t);
  cout << "total flow: " << cur_flow << endl;
}