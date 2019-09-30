#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define N 100005

vector<int> adj[N];
set<int> aps;
bool vis[N];
int dis[N], par[N], low[N], numBCC, t;  // t <- time;
bool ap[N];
stack<pii> stk;
vector<pii> bcc[N];

void reset(int n) {
  t = 0, numBCC = 0;
  for (int i = 0; i <= n; i++) {
    vis[i] = false;
    ap[i] = false;
    low[i] = 0;
    dis[i] = 0;
    adj[i].clear();
  }
}

void dfs(int u, int p) {
  vis[u] = true;
  low[u] = dis[u] = ++t;
  int numChild = 0;  // number of unvisited child

  for (int i = 0; i < adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == p) continue;  // if parent then ignore

    if (vis[v]) {
      if (low[u] > dis[v]) {
        stk.push({u, v});  // back-edge
        low[u] = dis[v];
      }
    } else {
      numChild++;
      stk.push({u, v});
      dfs(v, u);
      low[u] = min(low[u], low[v]);

      if (dis[u] <= low[v] && p != -1 || numChild > 1 && p == -1) {
        ap[u] = true;
        aps.insert(u);
        numBCC++;
        while (stk.top().first != u || stk.top().second != v) {
          bcc[numBCC].push_back(stk.top());
          stk.pop();
        }
        bcc[numBCC].push_back(stk.top());
        stk.pop();
      }
    }
  }
}

void dfs_init(int n) {
  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      dfs(i, -1);
      if (!stk.empty()) numBCC++;
      while (!stk.empty()) {
        bcc[numBCC].push_back(stk.top());
        stk.pop();
      }
    }
  }
}

void printAPs() {
  cout << "Total articulation points: " << aps.size() << " they are: \n";
  set<int>::iterator it;
  for (it = aps.begin(); it != aps.end(); it++) {
    cout << *it << " ";
  }
  printf("\n");
}

void printBCCs() {
  cout << "Toatal bccs are :" << numBCC << " they are" << endl;
  for (int i = 1; i <= numBCC; i++) {
    cout << "bcc no " << i << endl;
    for (int j = 0; j < bcc[i].size(); j++) {
      printf("%d %d\n", bcc[i][j].first, bcc[i][j].second);
    }
    puts("");
  }
}

int main() {
  int n, e;
  scanf("%d %d", &n, &e);
  reset(n);

  for (int i = 0; i < e; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  puts("");
  dfs_init(n);
  printBCCs();
}
