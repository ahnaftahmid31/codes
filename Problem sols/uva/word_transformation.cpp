#include <bits/stdc++.h>
using namespace std;

const int N = 205;

map<string, int> mp;
map<int, string> rev;
vector<string> words[10 + 5];
vector<int> adj[N];
int level[N], par[N];

void reset() {
  for (int i = 0; i < 15; i++)  words[i].clear();
  for (int i = 0; i<N; i++) adj[i].clear();
  rev.clear();
  mp.clear();
}

void make_graph() {
  for (int i = 1; i <= 10; i++) {
    for (int j = 0; j < words[i].size(); j++) {
      for (int k = 0; k < words[i].size(); k++) {
        if (j == k) continue;
        string s = words[i][j], t = words[i][k];
        int diff = 0;
        for (int c = 0; c < i; c++) if (s[c] != t[c]) diff++;
        if (diff == 1) {
          int u = mp[s], v = mp[t];
          adj[u].push_back(v);
        }
      }
    }
  }
}

int bfs(int s, int t) {
  queue<int> q;
  q.push(s);
  for (int i = 0; i < N; i++) level[i] = par[i] = -1;
  level[s] = 0;

  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (int v : adj[u]) {
      if (level[v] == -1) {
        level[v] = level[u] + 1;
        par[v] = u;
        if (v == t) return level[v];
        q.push(v);
      }
    }
  }
  return -1;
}

int main() {
  int cases;
  scanf("%d", &cases);
  while (cases--) {
    reset();
    string str;
    int id = 0;

    while (cin >> str) {
      if (str[0] == '*') { getchar(); break; }
      int sz = str.size();
      words[sz].push_back(str);
      if (!mp[str]) { mp[str] = ++id; }
    }
    make_graph();

    string s, t, r;
    while (getline(cin, r)) {
      istringstream ss(r); //I don't know what this is learned from fuad
      if (ss >> s) {
        ss >> t;
        int ans = bfs(mp[s], mp[t]);
        cout << s << " " << t << " " << ans << endl;
      } 
      else break;
    }
    if (cases != 0) cout << endl;
  }
}