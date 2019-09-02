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

void bfs(int s, int t) {
  priority_queue<edge> pq;
  cost[s] = 0;
  pq.push({s, 0});
  bool sp = false;

  while (!pq.empty()) {
    int u = pq.top().v;
    pq.pop();
    for (int i = 0; i < adj[u].size(); i++) {
      edge e = adj[u][i];
      if (e.v == t) {
        int s = cost[u] + e.w;
        if (!sp) {
          sp = true;
          spcost = s;
          par[t] = u;
        }
        costs.insert(s);
      } else if (cost[u] + e.w < cost[e.v]) {
        cost[e.v] = cost[u] + e.w;
        par[e.v] = u;
        pq.push(e);
      }
    }
  }
}

void goBack(int s, int t) {
  int minCost = inf;
  while (t != -1) {
    for (int i = 0; i < adj[t].size(); i++) 
      minCost = min(minCost, adj[t][i].w);
    t = par[t];
  }
  costs.insert(spcost + minCost * 2);
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
    bfs(1, n);
    goBack(1, n);
    set<int>::iterator it;
    it = costs.begin(), it++;
    //for (it = costs.begin(); it != costs.end(); it++) cout << *it << endl;
    printf("Case %d: %d\n", ++caseno, *it);
  }

  return 0;
}