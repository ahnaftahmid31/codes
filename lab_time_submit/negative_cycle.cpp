#include <bits/stdc++.h>
using namespace std;

const int N = 105;
#define inf 1 << 29

struct edge {
  int u, v, w;
  edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
};

vector<edge> edges;
int cost[N];

void reset(int n) {
  memset(cost, inf, sizeof(cost));
  edges.clear();
}

bool relax() {
  bool flag = false;
  for (int i = 0; i < edges.size(); i++) {
    edge e = edges[i];
    int u = e.u, v = e.v, w = e.w;
    if (cost[u] + w < cost[v]) {
      cost[v] = cost[u] + w;
      flag = true;
    }
  }
  if (flag)
    return true;
  else
    return false;
}

bool bell_ford(int n) {
  for (int i = 1; i <= n - 1; i++) {
    relax();
  }
  if (relax())
    return true;
  else
    return false;
}

int main() {
  int n, e;
  scanf("%d %d", &n, &e);
  reset(n);
  for (int i = 0; i < e; i++) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    edges.push_back(edge(u, v, w));
  }
  if (bell_ford(n))
    printf("Yes\n");
  else
    printf("No\n");
  return 0;
}