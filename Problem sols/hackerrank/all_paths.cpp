#include <bits/stdc++.h>
using namespace std;

const int N = 1003;
const int inf = INT_MAX / 2;
const int d = 10007;

int cost[N][N];

void reset(int n) { memset(cost, 0, sizeof(cost)); }

void fowarshal(int n) {
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        cost[i][j] = ((cost[i][k] % d) * (cost[k][j] % d) + cost[i][j] % d) % d;
      }
    }
  }
}

int main() {
  int cases;

  int n, e;
  cin >> n >> e;
  reset(n);
  for (int i = 0; i < e; i++) {
    int u, v, w;
    cin >> u >> v;
    cost[u][v] = 1;
  }
  fowarshal(n);
  int queries;
  scanf("%d", &queries);
  for (int i = 0; i < queries; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    printf("%d\n", cost[u][v]);
  }
}