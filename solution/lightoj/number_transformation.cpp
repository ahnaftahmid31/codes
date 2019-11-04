#include <bits/stdc++.h>
using namespace std;

vector<int> fac[1005];
int level[1005];
int vis[1005];

void sieve_factor() {
  bool p[1005]; memset(p, true, sizeof(p)); p[1] = false;
  int half = 500;
  
  for (int i = 2; i <= half; i++) {
    if (!p[i]) continue;
    for (int j = 2; j * i <= 1000; j++) {
      p[i * j] = false;
      fac[j * i].push_back(i);
    }
  }
}

int bfs(int s, int t) {
  if (s == t) return 0;
  if (s > t) return -1;
  queue<int> q;
  memset(vis, false, sizeof(vis));
  q.push(s);
  level[s] = 0;
  vis[s] = true;

  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (int i = 0; i < fac[u].size(); i++) {
      int v = u + fac[u][i];
      if (v > t) continue;
      if (!vis[v]) {
        level[v] = level[u] + 1;
        if (v == t) return level[v];
        vis[v] = true;
        q.push(v);
      }
    }
  }
  return -1;
}

int main() {
  sieve_factor();
  int caseno = 0, cases; scanf("%d", &cases);
  while (cases--) {
    int a, b; scanf("%d %d", &a, &b);
    printf("Case %d: %d\n", ++caseno, bfs(a, b));
  }
}