#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

vector<int> g[N];
bool vis[N];

void edge(int a, int b) {
  g[a].push_back(b);
  g[b].push_back(a);
}

bool isCycle(vector<int> g[], int i, int n) {
  int p = -1;
  queue<pair<int, int>> q;
  vis[i] = true;
  q.push(pair<int, int>(i, p));

  while (!q.empty()) {
    int u = q.front().first;
    int par = q.front().second;
    q.pop();

    for (auto v : g[u]) {
      if (!vis[v]) {
        vis[v] = true;
        q.push(pair<int, int> (v, u));
      } else if (par != v)
        return true;
    }
  }
  return false;
}

bool isDisconnected(vector<int> g[], int n) {
  for (int i = 0; i < n; i++)
    if (!vis[i] && isCycle(g, i, n)) return true;
  return false;
}

int main() {
  int n, e;
  cin >> n >> e;

  memset(vis, false, sizeof(vis));

  int u, v;
  for (int i = 0; i < e; i++) {
    cin >> u >> v;
    edge(u, v);
  }

  if (isDisconnected(g, n))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;

  return 0;
}