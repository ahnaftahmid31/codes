#include<bits/stdc++.h>
using namespace std;

#define  white 0
#define  grey 1
#define  black 2
#define  maxNodes 100005

vector <int> edgeof[maxNodes];
stack <int> stk;
int color[maxNodes];
int dis[maxNodes];
int fin[maxNodes];
bool has_cycle;
int t; // <-- time

void dfs(int u){
  color[u] = grey;
  dis[u] = ++t;

  for(int i = 0; i<edgeof[u].size(); i++){
    int v = edgeof[u][i];
    // if(color[v] == grey) {
    //   printf("back edge found : %d -> %d\n", u, v);
    //   has_cycle = true;
    // }
    if (color[v] == black) {
      has_cycle = true;
      return;
    }
    if (color[v] == white) {
      printf("  %d --> %d\n", u, v);
      dfs(v);
    }
  }

  color[u] = black;
  fin[u] = ++t;
  stk.push(u);
}

void dfs_init(int numVer){
  t = 0;
  has_cycle = false; 
  while(!stk.empty()) stk.pop();
  for(int i = 0; i<=numVer; i++){
    color[i] = white;
  }
  for(int i = 0; i<numVer; i++){
    if(color[i] == white){
      dfs(i);
      if(has_cycle) return;
    }
  }
}

// a function for displaying discovery time and finishing time
void printTheDisAndFin(int numVertex){
  cout << "vertex" << " dis" << "  fin" << "\n";
  for(int i = 0; i<numVertex; i++){
    cout << "  " << i << "     " << dis[i] << "   " << fin [i] <<"\n";
  }
}

// a function for printing topologically sorted nodes
void printTopSorted(int numVertex){
  while(!stk.empty()){
    printf("%d\n", stk.top());
    stk.pop();
  }
}

int main(){

  int numVertex, numEdges;
  scanf("%d %d", &numVertex, &numEdges);

  for(int i = 0; i<numEdges; i++){
    int u, v;
    scanf("%d %d", &u, &v);
    edgeof[u].push_back(v);
    edgeof[v].push_back(u);

  }
  dfs_init(numVertex);
  if (has_cycle) printf("yes\n");
  else
  {
    printf("no\n");
  }
  

}
