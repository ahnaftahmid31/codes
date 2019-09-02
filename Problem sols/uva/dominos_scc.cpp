#include<bits/stdc++.h>
using namespace std;

#define  white 0
#define  grey 1
#define  black 2
#define  N 100005

vector <int> reverseG[N];
vector <int> adj[N];
stack <int> stk;
int numComp;
int color[N];  // color for first dfs 
bool vis[N];   // vis for second dfs I know that's dumb :3
int indegree_scc[N];
int dominos = 0;
int scc_of[N];

void dfs(int u) {
  color[u] = grey;
  for(int i = 0; i<adj[u].size(); i++) {
    int v = adj[u][i];
    if(color[v] == white) {
      dfs(v);
    }
  }
  color[u] = black;
  stk.push(u);
}

void dfs_rev_graph(int u) {
  scc_of[u] = numComp;
  vis[u] = true;
  for(int i = 0; i<reverseG[u].size(); i++) {
    int v = reverseG[u][i];
    if(!vis[v]) {
      dfs_rev_graph(v);
    }
    if(scc_of[u] != scc_of[v]) {
      indegree_scc[numComp]++;
    }
  }
}

void dfs_init(int n) {
  //reseting
  for(int i = 1; i<=n; i++) {
    color[i] = white;
    vis[i] = false;
  }
  //1st dfs for topsort
  for(int i = 1; i<=n; i++) {
    if(color[i] == white) {
      dfs(i);
    }
  }
  //2nd dfs for scc
  numComp = 0;
  while(!stk.empty()) {
    int u = stk.top();
    stk.pop();
    if(!vis[u]) {
      numComp++;
      dfs_rev_graph(u);
    }
  }
  dominos = 0;
  for(int i = 1; i<=numComp; i++) {
    if(indegree_scc[i] == 0) {
      dominos++;
    }
  }
}

int main() {
  int cases;
  scanf("%d", &cases);

  while(cases--) {
    int n, e;
    scanf("%d %d", &n, &e);
    for(int i = 1; i<= n; i++) {
      adj[i].clear();
      reverseG[i].clear();
      indegree_scc[i] = 0;
    }
    for(int i = 0; i<e; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      adj[u].push_back(v);
      reverseG[v].push_back(u);
    }
    dfs_init(n);
    cout << dominos << endl;
  }
}
