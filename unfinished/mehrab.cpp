#include <bits/stdc++.h>
#include <limits.h>
using namespace std;
#define INF INT_MAX

int t, V, E, u, v, q;
long long int a, w;
long long int dist[100][100];
long long int tim[100][100];

bool shouldChange(int i, int j, int k) {
  return (tim[i][k] + tim[k][j] < tim[i][j] && tim[i][k] != INF &&
          tim[k][j] != INF && dist[i][k] != INF && dist[k][j] != INF) ||
         (tim[i][k] + tim[k][j] == tim[i][j] &&
          dist[i][k] + dist[k][j] < dist[i][j] && tim[i][k] != INF &&
          tim[k][j] != INF && dist[i][k] != INF && dist[k][j] != INF);
}

bool shouldUpdate(int u, int v, int a, int w) {
  return ((a < tim[u][v]) || (a == tim[u][v] && w < dist[u][v]));
}

void floydWarshall() {
  for (int k = 1; k <= V; k++) {
    for (int i = 1; i <= V; i++) {
      for (int j = 1; j <= V; j++) {
        if (shouldChange(i, j, k)) {
          tim[i][j] = tim[i][k] + tim[k][j];
          dist[i][j] = dist[i][k] + dist[k][j];
        }
      }
    }
  }
}

int main() {
  cin >> t;
  while (t--) {
    cin >> V >> E;
    for (int i = 0; i <= V; i++) {
      for (int j = 0; j <= V; j++) {
        dist[i][j] = INF;
        tim[i][j] = INF;
      }
    }

    for (int i = 0; i < E; i++) {
      cin >> u >> v >> a >> w;
      if (shouldUpdate(u, v, a, w)) {
        tim[u][v] = tim[v][u] = a;
        dist[u][v] = dist[v][u] = w;
      }
    }

    floydWarshall();

    cin >> q;
    while (q--) {
      cin >> u >> v;
      if (tim[u][v] == INF || dist[u][v] == INF)
        cout << "No Path." << endl;
      else
        cout << "Distance and time to reach destination is " << dist[u][v]
             << " & " << tim[u][v] << "." << endl;
    }

    if (t) puts("");
  }
  return 0;
}