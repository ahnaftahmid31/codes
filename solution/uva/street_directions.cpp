#include<bits/stdc++.h>
using namespace std;

#define  white 0
#define  grey 1
#define  black 2
#define  N 100005

struct edge{
  int u, v; //u -> v
  edge(int _u, int _v) {
    u = _u;
    v = _v;
  }
};
vector<edge> street;
vector <int> reverseG[N];
vector <int> adj[N];
stack <int> stk;
int numComp;
int color[N];  // color for first dfs
bool vis[N];   // vis for second dfs I know that's dumb :3
int scc_of[N];

void dfs(int u, int p) {
  color[u] = grey;
  for(int i = 0; i<adj[u].size(); i++) {
    int v = adj[u][i];
    if(v == p) continue;
    if(color[v] != black) {
      reverseG[v].push_back(u);
      street.push_back(edge(u, v));
      if(color[v] == white) {
        dfs(v, u);
      }
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
      street.push_back(edge(u, v));
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
      dfs(i, -1);
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
}


int main() {
  int n, e, cases = 0;
  while(true) {
    scanf("%d %d", &n, &e);
    if(n == 0 && e == 0) break;

    for(int i = 1; i<= n; i++) {
      adj[i].clear();
      reverseG[i].clear();
    }
    street.clear();

    for(int i = 0; i<e; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    dfs_init(n);
    cout << ++cases << endl;
    cout << endl;
    for(int i = 0; i<street.size(); i++) {
      cout << street[i].u << " " << street[i].v << endl;
    }
    cout << "#" << endl;
  }
}
