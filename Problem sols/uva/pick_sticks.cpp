#include<bits/stdc++.h>
using namespace std;

#define N 1000006
#define white 0
#define black 2
#define grey 1

vector <int> adj[N];
stack <int> stk;
int color[N];
bool hasCycle;

void dfs(int u) {

  color[u] = grey;
  for(int i = 0; i<adj[u].size(); i++) {
    int v = adj[u][i];
    
    if(color[v] == grey) {
      hasCycle = true;
      return;
    }
    if(color[v] == white) {
      dfs(v);
    }
  }
  color[u] = black;
  stk.push(u);
}

int main() {
  while(true) {
    int n, e;
    scanf("%d %d", &n, &e);
    if(n == 0 && e == 0) break;

    for(int i = 0; i<=n; i++) {
      color[i] = white;
      adj[i].clear();
    }
    hasCycle = false;

    for(int i = 0; i<e; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      adj[u].push_back(v);
    }
      
    for(int i = 1; i<=n; i++) {
      if(color[i] == white) {
        dfs(i);
      }
    }
    if(hasCycle) {
      printf("IMPOSSIBLE\n");
      while(!stk.empty()) {
        stk.pop();
      }
    }
    else{
      while(!stk.empty()) {
        printf("%d\n", stk.top());
        stk.pop();
      }
    }    
  }
}

