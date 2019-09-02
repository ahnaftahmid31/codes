#include<bits/stdc++.h>
using namespace std;

#define N 1003

vector<int> adj[N];
vector<int> value;
int learnt;
int last_node;

void reset(int n) {
	value.clear();
	learnt = 0;
	last_node = 0;
	for(int i = 0; i<=n; i++){
		adj[i].clear();
	}
}

int get_max(int source) {
	int max = -1;
	int max_node = -1;
	for(int i = 0; i<adj[source].size(); i++) {
		if(max < value[adj[source][i]]){
			max = value[adj[source][i]];
			max_node = adj[source][i];
		}
	}
	return max_node;
}

void learn(int u) {
	int v = get_max(u);
	if(v == -1) {
		last_node = u;
		return;
	}
	else {
		learnt += value[v];
		learn(v);
	}
}

int main() {
  int cases;
	scanf("%d", &cases);

	for(int caseNo = 1; caseNo <= cases; caseNo++){
		int n, e;

		scanf("%d %d", &n, &e);
		reset(n);

		for(int i = 0; i<n; i++) {
			int learning_unit;

			scanf("%d", &learning_unit);
			value.push_back(learning_unit); //pushing unit for i-th node
		}
		for(int i = 0; i<e; i++) {
			int u, v;

			scanf("%d %d", &u, &v);
			adj[u].push_back(v); // u --> v (it's a direct acyclic graph)
		}

		learn(0);
		printf("Case %d: %d %d\n", caseNo, learnt, last_node);
	}
}