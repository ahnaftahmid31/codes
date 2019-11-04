#include <bits/stdc++.h>
using namespace std;

#define N 1003
#define inf 1 << 30

int nuts, bolts;
int fits[N][N];

vector<int> adj[N];
int res_cap[N][N];
vector<int> par(N);
int max_flow;

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
int edmond_karp(int s, int t) {
  max_flow = 0;
  int flow;

  while (flow = bfs(s, t)) {  // return a flow until there is no path left
    max_flow += flow;
    int v = t;

    while (v != s) {
      int u = par[v];
      res_cap[u][v] -= flow;
      res_cap[v][u] += flow;
      v = u;
    }
  }
  return max_flow;
}

void make_flow_graph() {
  for (int b = 0; b < bolts; b++) {
    for (int n = 0; n < nuts; n++) {
      if (fits[b][n]) {
        int u = b + 1, v = bolts + n + 1;
        
        res_cap[u][v] = 1;
        res_cap[v][u] = 0;
        adj[u].push_back(v);
        adj[v].push_back(u);
      }
    }
  }
  // 0 is the source and bolts + 1 is the sink
  for (int i = 1; i <= bolts; i++) {
    int u = 0, v = i;
    res_cap[u][v] = 1;
    res_cap[v][u] = 0;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (int i = 1; i <= nuts; i++) {
    int u = bolts + i, v = bolts + nuts + 1;
    res_cap[u][v] = 1;
    res_cap[v][u] = 0;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
}

void reset() {
  memset(fits, 0, sizeof(fits));
  memset(res_cap, 0, sizeof(res_cap));
  for(int i = 0; i<=bolts + nuts + 1; i++) {
    adj[i].clear();
  }
}

void read_input_data(void) {
  int n, b;
  scanf("%d%d", &bolts, &nuts);
  reset();

  for (b = 0; b < bolts; b++) {
    for (n = 0; n < nuts; n++) {
      scanf("%d", &fits[b][n]);
    }
  }
}

int main() {
  int cases, caseno;
  scanf("%d", &cases);
  for (caseno = 1; caseno <= cases; caseno++) {
    read_input_data();
    make_flow_graph();
    edmond_karp(0, bolts + nuts + 1);
    
    printf("Case %d: ", caseno);
    printf("a maximum of %d nuts and bolts ", max_flow);
    printf("can be fitted together\n");
  }
  return 0;
}