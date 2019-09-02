#include<bits/stdc++.h>
using namespace std;

#define N 5004

map<int, char> revmp;
map<char, int> mp;
vector<int> adj[N];
bool vis[N];
stack<int> stk;
string idx[N];

void dfs(int u) {
  vis[u] = true;
  for(int i = 0; i < adj[u].size(); i++) {
    int v = adj[u][i];
    if(!vis[v]) {
      dfs(v);
    }
  }
  stk.push(u);
}
void dfs_init(int nodes) {
  for(int i = 0; i<=nodes; i++) {
    vis[i] = false;
  }
  for(int i = 1; i<= nodes; i++) {
    if(!vis[i]) {
      dfs(i);
    }
  }
}
void find_relation(int rows, int nodes) {
  for(int i = 0; i < rows - 1; i++) {
    int length = min(idx[i].length(), idx[i + 1].length());

    for(int j = 0; j<length; j++) {
      char u = idx[i][j];
      char v = idx[i + 1][j];
      if(u != v) {
        adj[mp[u]].push_back(mp[v]);
        break; //if diff found break loop immediately
      }
    }
  }
  dfs_init(nodes);
}

int main() {

  int rows = 0;
  int id = 0;
  while(true) {
    string str;
    cin >> str;
    if(str[0] == '#') break;
    idx[rows] = str;
    for(int i = 0; i<str.length(); i++) {
      if(!mp[str[i]]) {
        mp[str[i]] = ++id;
        revmp[id] = str[i];
      }
    }
    rows++;
  }
  find_relation(rows, id);
  while(!stk.empty()) {
    cout << revmp[stk.top()];
    stk.pop();
  }
  cout << endl;
}
