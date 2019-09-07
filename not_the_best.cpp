#include <bits/stdc++.h>
using namespace std;
const int N = 10004;
#define inf 1 << 29

struct edge {
  int v, w;
  edge(int _v, int _w) : v(_v), w(_w) {}
  bool operator<(const edge &p) const { return w > p.w; }
};

vector<edge> adj[N];
int cost[N], par[N], spcost;
set<int> costs;

void reset(int n) {
  for (int i = 0; i <= n; i++) {
    adj[i].clear();
    cost[i] = inf;
    par[i] = -1;
  }
  costs.clear();
}



int main() {
  int cases, caseno = 0;
  scanf("%d", &cases);
  while (cases--) {
    int n, e;
    scanf("%d %d", &n, &e);
    reset(n);

    for (int i = 0; i < e; i++) {
      int u, v, w;
      scanf("%d %d %d", &u, &v, &w);
      adj[u].push_back(edge(v, w));
      adj[v].push_back(edge(u, w));
    }
    
    printf("");
  }

  return 0;
}