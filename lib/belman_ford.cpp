#include <bits/stdc++.h>
using namespace std;

#define inf 1 << 30
#define N 100005

struct edge {
  int u, v, w;
  edge(int _u, int _v, int _w) {
    u = _u;
    v = _v;
    w = _w;
  }
  bool operator<(const edge &p) const { return w < p.w; }
};

vector<edge> edges;
int dis[N];
int previous[N];
stack<int> path;

bool relax_path() {
  bool cycle = false;
  for (int i = 0; i < edges.size(); i++) {
    int u = edges[i].u;
    int v = edges[i].v;
    int w = edges[i].w;
    if (dis[v] > w + dis[u]) {
      dis[v] = w + dis[u];
      previous[v] = u;
      cycle = true;
    }
  }
  if (cycle) return true;
  return false;
}

bool bell_ford(int s, int n, int x) {
  for (int i = 0; i <= n; i++) {
    dis[i] = inf;
    previous[i] = -1;
  }
  dis[s] = 0;
  for (int i = 0; i < x; i++) {
    relax_path();
  }
  if (!relax_path()) {  // negetive cycle doesn't exist
    cout << "negetive cycle doesn't exist\n";
    return false;
  } else {  // negetive cycle exists
    cout << "negetive cycle exists\n";
    return true;
  }
}

void find_path(int des) {
  if (des == -1) return;
  path.push(des);
  find_path(previous[des]);
}

void print_path(int des) {
  find_path(des);
  while (path.size() != 1) {
    cout << path.top() << " -> ";
    path.pop();
  }
  cout << path.top() << " = " << dis[des] << endl;
  path.pop();
}

int main() {
  int n, e;
  scanf("%d %d", &n, &e);
  for (int i = 0; i < e; i++) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    edges.push_back(edge(u, v, w));
    // edges.push_back(edge(v, u, w));
  }
  bell_ford(1, n, n - 1);
  print_path(n);
}