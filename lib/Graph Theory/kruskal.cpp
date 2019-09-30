#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define N 100005

struct edge {
  int u, v, w;
  bool operator<(const edge &p) const { return w < p.w; }
};

int par[N];
vector<edge> edges;
vector<edge> mst;

void makeset(int n) {
  for (int i = 0; i <= n; i++) {
    par[i] = i;
  }
}

int find(int x) {
  par[x] = (x != par[x]) ? find(par[x]) : x;
  return par[x];
}

int kruskal(int n) {
  sort(edges.begin(), edges.end());
  makeset(n);

  int count = 0;
  int totalcost = 0;

  for (int i = 0; i < edges.size(); i++) {
    edge e = edges[i];
    int pu = find(e.u);
    int pv = find(e.v);
    if (pu != pv) {
      par[pv] = pu;
      count++;
      totalcost += e.w;
      mst.push_back(e);
      if (count == n - 1) {  // because there will be n - 1 edges
        break;
      }
    }
  }
  return totalcost;
}

void printMst() {
  printf("Printing mst :\n");
  for (int i = 0; i < mst.size(); i++) {
    cout << mst[i].u << "-" << mst[i].v << " : " << mst[i].w << endl;
  }
}

int main() {
  int n, e;
  scanf("%d %d", &n, &e);
  for (int i = 0; i < e; i++) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    edge e;
    e.u = u;
    e.v = v;
    e.w = w;
    edges.push_back(e);
  }
  cout << kruskal(n) << endl;
  printMst();
}
