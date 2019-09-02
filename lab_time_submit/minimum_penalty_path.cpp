#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
const int N = 1003;

vector<int> adj[N], cost[N];
bool possible[N][1025], vis[N];

void reset(int n) {
  for (int i = 0; i <= n; i++) {
    adj[i].clear();
    cost[i].clear();
  }
  memset(possible, 0, sizeof(possible));
}

void bfs(int s, int t) {
  queue<pii> q;
  q.push({s, 0});
  possible[s][0] = true;

  while (!q.empty()) {
    int u = q.front().first;
    int val = q.front().second;
    q.pop();
    for (int i = 0; i < adj[u].size(); i++) {
      int v = adj[u][i];
      int bitCost = cost[u][i] | val;

      if (!possible[v][bitCost]) {
        possible[v][bitCost] = true;
        q.push({v, bitCost});
      } 
    }
  }
}

int main() {
  int n, e;
  scanf("%d %d", &n, &e);
  reset(n);
  for (int i = 0; i < e; i++) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    adj[u].push_back(v);
    adj[v].push_back(u);
    cost[u].push_back(w);
    cost[v].push_back(w);
  }
  int s, t;
  scanf("%d %d", &s, &t);

  bfs(s, t);
  int ans = -1;
  for (int i = 0; i < 1024; i++) {
    if (possible[t][i]) {
      ans = i;
      break;
    }
  }
  printf("%d\n", ans);
}