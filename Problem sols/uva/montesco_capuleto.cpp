#include <bits/stdc++.h>
using namespace std;

#define white 0
#define red 1
#define blue 2
#define N 100005

vector<int> adj[N];
int color[N];
bool vis[N];

void reset(int n){
	for (int i = 0; i <= 200; i++){
		adj[i].clear();
		vis[i] = false;
		color[i] = white;
	}
}

void haha()
{
}

int bfs(int source, int n){
	color[source] = red;
	vis[source] = true;
	queue<int> q;
	q.push(source);
	int num_red = 1, num_blue = 0;
	int count = 0;
	bool hasCycle = false;
	bool is_blue = true;
	bool is_red = true;

	while (!q.empty()){
		int u = q.front();
		q.pop();
		for (int i = 0; i < adj[u].size(); i++){
			int v = adj[u][i];
			if (color[v] == white){
				vis[v] = true;
				if (color[u] == red){
					color[v] = blue;
					num_blue++;
					if (v > n){
						num_blue = 0;
						is_blue = false;
					}
				}
				else{
					color[v] = red;
					num_red++;
					if (v > n){
						num_red = 0;
						is_red = false;
					}
				}
				q.push(v);
			}
			else if (color[u] == color[v]){
				hasCycle = true;
			}
		}
	}
	if (hasCycle) count = 0;
	else{
		if (!is_blue)	num_blue = 0;
		if (!is_red) num_red = 0;
		count = max(num_blue, num_red);
	}
	return count;
}

int main(){
	int cases;
	scanf("%d", &cases);
	while (cases--){
		int n, e;
		scanf("%d", &n);
		reset(n);

		for (int i = 1; i <= n; i++){
			scanf("%d", &e);
			for (int j = 1; j <= e; j++){
				int v;
				scanf("%d", &v);
				adj[i].push_back(v);
				adj[v].push_back(i);
			}
		}
		int people = 0;
		for (int i = 1; i <= n; i++){
			if (!vis[i]){
				people += bfs(i, n);
			}
		}
		cout << people << endl;
	}
}
