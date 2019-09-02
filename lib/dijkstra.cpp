#include <bits/stdc++.h>
using namespace std;

#define N 100005
#define inf 1 << 30

struct node {
  int u, w;
  node(int _u, int _w) {
    u = _u;
    w = _w;
  }
  bool operator<(const node &p) const {
    return w > p.w;  // why ? for avoiding greater<int> ... in priority queue
  }
};

vector<int> adj[N];
vector<int> cost[N];
vector<int> path;
int dis[N];
int from[N];

void bfs(int s, int n, int des) {
  for (int i = 0; i <= n; i++) {
    dis[i] = inf;
    from[i] = -1;
  }

  priority_queue<node> pq;
  pq.push(node(s, 0));
  dis[s] = 0;

  int count = 0;
  while (!pq.empty()) {
    node top = pq.top();
    int u = top.u;
    pq.pop();

    ++count;
    for (int i = 0; i < adj[u].size(); i++) {
      int v = adj[u][i];

      if (cost[u][i] + dis[u] < dis[v]) {
        dis[v] = cost[u][i] + dis[u];
        pq.push(node(v, dis[v]));
        from[v] = u;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << s << " --> " << i << " = " << dis[i] << endl;
  }
  cout << " total call: " << count << endl;

  int t = des;
  while (t != -1) {
    path.push_back(t);
    t = from[t];
  }
}

void printPath() { // print the path from source to destination
  int k;
  for (k = path.size() - 1; k > 0; k--) {
    printf("%d -> ", path[k]);
  }
  printf("%d\n", path[k]);
}

int main() {
  int n, e;
  scanf("%d %d", &n, &e);
  for (int i = 0; i < e; i++) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    adj[u].push_back(v);
    adj[v].push_back(u);
    cost[u].push_back(w);
    cost[v].push_back(w);
  }
  int des = n; // destinatino from source.
  bfs(1, n, des);
  printPath();
}
