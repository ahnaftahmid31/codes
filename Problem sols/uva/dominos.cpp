#include<bits/stdc++.h>
using namespace std;

#define N 100005

vector <int> adj[N];
bool vis[N];
stack<int> stk;

void dfs (int u) {
  vis[u] = true;
  for(int i = 0; i<adj[u].size(); i++) {
    int v = adj[u][i];
    if(!vis[v]) {
      dfs(v);
    }
  }
  stk.push(u);
}

void dfs_dominos(int u) {
  vis[u] = false;
  for(int i = 0; i<adj[u].size(); i++) {
    int v = adj[u][i];
    if(vis[v]) {
      dfs_dominos(v);
    }
  }
}
void reset (int n) {
  for(int i = 1; i<=n; i++) {
    vis[i] = false;
    adj[i].clear();
  }
}

int dominosCounting(int n) {
  for(int i = 1; i<=n; i++) {
    if(!vis[i]) {
      dfs(i);
    }
  }
  int dominos = 0;
  while(!stk.empty()) {
    int u = stk.top();
    stk.pop();
    if(vis[u]) {
      dfs_dominos(u);
      dominos++;
    }
  }
  return dominos;
}
int main () {
  int cases;
  scanf("%d", &cases);
  while(cases--) {
    int n, e;
    scanf("%d %d", &n, &e);
    reset(n);
    for(int i  = 0; i<e; i++) {
      int u , v;
      scanf("%d %d", &u, &v);
      adj[u].push_back(v);
    }
    cout << dominosCounting(n) << endl;
  }
}
