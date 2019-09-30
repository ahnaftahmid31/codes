#include<bits/stdc++.h>
using namespace std;

#define N 100005

int par[N];

void makeset(int n) {
  for(int i = 0; i<n; i++) {
    par[i] = i;
  }
}

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
void printTree(int n){
	for(int i = 0; i<n; i++){
			cout << i << " -> " << find(i) << endl;
	}
}

int main(){
	int n, e;
	scanf("%d", &n);
	makeset(n);
	scanf("%d", &e);
	for(int i = 0; i<e; i++){
			int u, v;
			scanf("%d %d", &u, &v);
			unify(u, v);
	}
	printTree(n);
}
