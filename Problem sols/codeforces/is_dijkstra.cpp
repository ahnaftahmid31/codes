#include <bits/stdc++.h>
using namespace std;

#define N 100005
#define inf 1 << 30

struct edge {
  int node, weight;
  edge(int _u, int _w) {
    node = _u;
    weight = _w;
  }
  bool operator<(const edge &p) const { return weight > p.weight; }
};

vector<edge> adj[N];
vector<int> path;
int dis[N];
int from[N];

void bfs(int s, int n) {
  for (int i = 1; i <= n; i++) {
    dis[i] = inf;
    from[i] = -1;  // i comes from -1
  }
  dis[s] = 0;
  priority_queue<edge> pq;
  pq.push(edge(s, dis[s]));

  while (!pq.empty()) {
    edge top = pq.top();
    pq.pop();
    int u = top.node;
    for (int i = 0; i < adj[u].size(); i++) {
      int v = adj[u][i].node;
      int cost = adj[u][i].weight;
      if (dis[v] > dis[u] + cost) {
        dis[v] = dis[u] + cost;
        pq.push(edge(v, dis[v]));
        from[v] = u;
      }
    }
  }
  int t = n;
  while (t != -1) {
    path.push_back(t);
    t = from[t];
  }
}

void printPath() {
  int k;
  for (k = path.size() - 1; k > 0; k--) {
    printf("%d ", path[k]);
  }
  printf("%d\n", path[k]);
}

int main() {
  int n, e;
  scanf("%d %d", &n, &e);
  for (int i = 0; i < e; i++) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    adj[u].push_back(edge(v, w));
    adj[v].push_back(edge(u, w));
  }
  bfs(1, n);
  printPath();
}
