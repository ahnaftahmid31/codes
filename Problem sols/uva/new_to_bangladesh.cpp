#include <bits/stdc++.h>
using namespace std;

#define N 105
#define inf 1 << 30

struct node {
  int u, w, t;
  node(int _u, int _t, int _w) : u(_u), t(_t), w(_w) {}
  bool operator<(const node &p) const {
    if (t == p.t) return w > p.w;
    else return t > p.t;
  }
};

vector<int> adj[N];
vector<int> cost[N];
vector<int> tym[N];
int dis[N], somoy[N];

void reset(int n) {
  for (int i = 0; i <= n; i++) {
    adj[i].clear();
    cost[i].clear();
    tym[i].clear();
  }
}

void bfs(int s, int n) {
  for (int i = 0; i<=n; i++) {
    dis[i] = inf;
    somoy[i] = inf;
  }
  priority_queue<node> pq;
  pq.push(node(s, 0, 0));
  dis[s] = 0;
  somoy[s] = 0;

  while (!pq.empty()) {
    int u = pq.top().u;
    pq.pop();
    for (int i = 0; i < adj[u].size(); i++) {
      int v = adj[u][i];
      if (tym[u][i] + somoy[u] < somoy[v]) {
        dis[v] = cost[u][i] + dis[u];
        somoy[v] = tym[u][i] + somoy[u];
        pq.push(node(v, dis[v], somoy[v]));
      }
      else if (tym[u][i] + somoy[u] == somoy[v]) {
        if (dis[u] + cost[u][i] < dis[v]) {
          dis[v] = dis[u] + cost[u][i];
          pq.push(node(v, dis[v], somoy[v]));
        }
      }
    }
  }
  return;
}

int main() {
  int cases;
  scanf("%d", &cases);
  while (cases--) {
    int n, e;
    scanf("%d %d", &n, &e);
    reset(n);
    for (int i = 0; i < e; i++) {
      int u, v, w, t;
      scanf("%d %d %d %d", &u, &v, &t, &w);
      adj[u].push_back(v);
      adj[v].push_back(u);
      cost[u].push_back(w);
      cost[v].push_back(w);
      tym[u].push_back(t);
      tym[v].push_back(t);
    }
    int query;
    scanf("%d", &query);
    while (query--) {
      int s, t;
      scanf("%d %d", &s, &t);
      bfs(s, n);
      int s_dis = dis[t], s_time = somoy[t];
      if (s_dis != inf) {
        printf("Distance and time to reach destination ");
        printf("is %d & %d.\n", s_dis, s_time);
      }
      else printf("No Path.\n");
    }
    if (cases != 0) puts("");
  }
}
