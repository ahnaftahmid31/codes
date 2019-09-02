#include <bits/stdc++.h>
using namespace std;

struct edge {
  int u, v, w;
  edge(int _u, int _v, int _w) {
    u = _u;
    v = _v;
    w = _w;
  }
  bool operator<(const edge &p) const { return w < p.w; }
};

vector<edge> mst;
vector<edge> edges;
const int N = 100005;
int par[N];

void makeset(int n) {
  for (int i = 0; i < n; i++) {
    par[i] = i;
  }
}

int find(int u) {
  par[u] = (u != par[u]) ? find(par[u]) : u;
  return par[u];
}

int kruskal(int n) {
  int total_cost = 0, count = 0;

  for (int i = 0; i < edges.size(); i++) {
    int u = edges[i].u;
    int v = edges[i].v;
    int pu = find(u);
    int pv = find(v);

    if (pv != pu) {
      par[pv] = pu;
      mst.push_back(edges[i]);
      total_cost += edges[i].w;
      count++;
      if (count == n - 1) break;
    }
  }
  return total_cost;
}

int second(int n) {
  sort(edges.begin(), edges.end());
  makeset(n);

  int best = kruskal(n);
  int sec_best = 9999999;

  for (int i = 0; i < mst.size(); i++) {
    edge e = mst[i];
    makeset(n);
    int total_cost = 0, count = 0;

    for (int j = 0; j < edges.size(); j++) {
      if (e.u == edges[j].u && e.v == edges[j].v && e.w == edges[j].w) continue;
      int u = edges[j].u;
      int v = edges[j].v;
      int pu = find(u);
      int pv = find(v);

      if (pv != pu) {
        par[pv] = pu;
        total_cost += edges[j].w;
        count++;
        if (count == n - 1) break;
      }
    }
    if (total_cost < sec_best) sec_best = total_cost;
  }
  return sec_best;
}

int main() {
  int n, e;
  scanf("%d %d", &n, &e);
  for (int i = 0; i < e; i++) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    edges.push_back(edge(u, v, w));
  }
  cout << second(n) << endl;
}