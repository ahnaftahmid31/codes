#include <bits/stdc++.h>
using namespace std;

#define N 100005

struct edge {
  int u, v, w;
  bool operator<(const edge& p) const { return w < p.w; }
  bool operator>(const edge& p) const { return w > p.w; }
};

vector<edge> adj[N];
vector<edge> mst;
int par[N];

void makeset(int n) {
  for (int i = 0; i < n; i++) {
    par[i] = i;
  }
}

int find(int x) {
  par[x] = (x != par[x]) ? find(par[x]) : x;
  return par[x];
}

int prim(int s, int n) {
  // makes a fresh disjoint set
  makeset(n);
  // a priority queue whose top element should be the lowest weighted edge
  priority_queue<edge, vector<edge>, greater<edge> > pq;
  // pushing source node's adj edges
  for (int i = 0; i < adj[s].size(); i++) {
    pq.push(adj[s][i]);
  }

  int count = 0;
  int totalcost = 0;

  while (!pq.empty()) {
    edge e = pq.top();
    pq.pop();

    int pu = find(e.u);
    int pv = find(e.v);
    if (pv != pu) {
      par[pv] = pu;
      for (int i = 0; i < adj[e.v].size(); i++) {
        pq.push(adj[e.v][i]);
      }
      totalcost += e.w;
      mst.push_back(e);
      if (++count == n - 1) break;  // because there will be n - 1 edges
    }
  }
  return totalcost;
}

void printMst() {
  printf("Printing mst:\n");
  for (int i = 0; i < mst.size(); i++) {
    cout << mst[i].u << "-" << mst[i].v << " : " << mst[i].w << endl;
  }
}

int main() {
  int n, e, source = 1;  // source can be 1, 2, anything
  scanf("%d %d", &n, &e);

  for (int i = 0; i < e; i++) {
    int u, v, w;
    edge e1, e2;

    scanf("%d %d %d", &u, &v, &w);
    e1.u = e2.v = u;
    e1.v = e2.u = v;
    e1.w = e2.w = w;
    adj[u].push_back(e1);
    adj[v].push_back(e2);
  }

  cout << "Total Cost: " << prim(source, n) << endl;
  printMst();
}
