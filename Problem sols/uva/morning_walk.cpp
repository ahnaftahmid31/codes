#include<bits/stdc++.h>
using namespace std;

#define N 1003

bool used[N];
int degree[N];
int par[N];

int find(int x){
  par[x] = (x != par[x]) ? find(par[x]) : x;
  return par[x];
}

void unify(int u , int v){
	int pu = find(u); //parent of u (actually representative)
	int pv = find(v); // parent of v ( " " )
	if(pu != pv){
			par[pv] = pu;
	}
}

int main() {
  int n, e;
  while(scanf("%d %d", &n, &e) != EOF) {
    for(int i = 0; i<n; i++) {
      used[i] = false;
      degree[i] = 0;
      par[i] = i;
    }
    for(int i = 0; i<e; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      unify(u, v);
      degree[u] ++, degree[v] ++;
      used[u] = used[v] = true;
    }
    bool possible = true;
    vector <int> usedNodes;
    for(int i = 0; i<n; i++) {
      if(used[i]) {
        usedNodes.push_back(i);
        find(i);
      }
    }
    int v;
    if(e > 0) {
      v = usedNodes[0];
      for(int i = 0; i < usedNodes.size(); i++) {
        int u = usedNodes[i];
        //cout << u << " degree: " << degree[u] << " res: " << par[u] << endl;
        if(par[u] != par[v] || degree[u] % 2 != 0 || degree[u] == 0) {
          possible = false;
          break;
        }
      }
    }
    if(e == 0) possible = false;
    if(possible) printf("Possible\n");
    else printf("Not Possible\n");
  }
}
