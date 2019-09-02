#include<bits/stdc++.h>
using namespace std;

#define  white 0
#define  grey 1
#define  black 2
#define  N 100005

map <string, int> mp;
vector <int> reverseG[N];
vector <int> adj[N];
vector <int> components[N];
stack <int> stk;
int numComp;
int color[N];  // color for first dfs 
bool vis[N];   // vis for second dfs I know that's dumb :3
int indegree_scc[N];
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
  //components[numComp].push_back(u);
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
    components[i].clear();
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
}

void printComponents() {
  int i, j;
  for( i = 1; i<=numComp; i++) {
    cout << "comp no: " <<  i << " has --> ";
    for( j = 0; j<components[i].size() -1; j++) {
      cout << components[i][j] << ", ";
    }
    cout << components[i][j];
    cout << "\n";
  }
  cout << "total : " << numComp << "\n";
}

void printIndegreeSCC() {
  for(int i = 1; i <= numComp; i++) {
    cout << i << "-th scc have/has indegree :" << indegree_scc[i] << endl;
  }
}

int main() {
 
  while(true) {
    int n, e;
    cin >> n >> e;
    if(n == 0 && e == 0) break;
    //resetting
    for(int i = 1; i<= n; i++) {
      adj[i].clear();
      reverseG[i].clear();
      indegree_scc[i] = 0;
    }
    mp.clear();
    //input
    getchar();
    for(int i = 1; i<=n; i++) {
      string name;
      getline(cin, name);
      mp[name] = i;
    }
    for(int i = 1; i<=e; i++) {
      string name1, name2;
      getline(cin, name1);
      getline(cin, name2);
      int u = mp[name1];
      int v = mp[name2];
      adj[u].push_back(v);
      reverseG[v].push_back(u);
    }
    dfs_init(n);
    cout << numComp << endl;
  }
}
