#include <bits/stdc++.h>
using namespace std;

struct edge {
  int u, v;
  edge(int _u, int _v) : u(_u), v(_v) {}
  bool operator<(const edge &p) const {
    if (u == p.u) return v < p.v;
    return u < p.u;
  }
};
const int N = 1003;   // max nodes
const int M = 20004;  // max edges

vector<int> adj[N];
int deg[N], indeg[N], outdeg[N];

void reset(int n) {
  for (int i = 0; i <= n; i++) adj[i].clear();
  edges.clear();
  memset(deg, 0, n + 3);
  memset(indeg, 0, n + 3);
  memset(outdeg, 0, n + 3);
}

bool isCircuit(int n) {
  for (int i = 1; i <= n; i++) {
    if (indeg[i] != outdeg[i]) return false;
  }
  return true;
}

bool isPath(int n) {
  int diffDeg = 0;
  for (int i = 1; i <= n; i++) {
    if (indeg[i] != outdeg[i]) {
      if (abs((long)(indeg[i] - outdeg[i])) == 1) {
        diffDeg++;
      }
    }
  }
  if (diffDeg == 2) return true;
  return false;
}

map<edge, bool> edges;
stack<int> stk;
void findPath(int u) {
  for (int v : adj[u]) {
    if (edges[{u, v}]) {
      edges[{u, v}] = false;
      findPath(v);
    }
  }
  stk.push(u);
}

void printPath() {
  while (!stk.empty()) {
    if (stk.size() == 1)
      printf("%d\n", stk.top());
    else
      printf("%d- >", stk.top());
    stk.pop();
  }
}

int main() {
  int n, e;
  cin >> n >> e;

  for (int i = 0; i < e; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    indeg[v]++;
    outdeg[u]++;
    adj[u].emplace_back(v);
    edges[{u, v}] = true;
  }
  if (isCircuit(n)) {
    printf("is circuit\n");
    findPath(1);
    printPath();
  } else if (isPath(n)) {
    printf("is path\n");
    findPath(1);
    printPath();
  } else
    printf("nothing\n");
}