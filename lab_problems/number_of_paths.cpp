#include <bits/stdc++.h>
using namespace std;

#define inf 1 << 29
const int N = 105;

int cost[N][N];
// int paths[N][N];

void reset(int n) {
  memset(cost, 0, sizeof(cost));
  // memset(paths, 0, sizeof(paths));
  // // for (int i = 1; i<=n; i++) {
  // //   for (int j = 1; j<=n; j++) {

  // //   }
  // // }
}

void fowarshall(int n) {
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (cost[i][k] && cost[k][j]) {
          cost[i][j] += cost[i][k] * cost[k][j];
          cost[i][j] = cost[i][j] % 10007;
        }
      }
    }
  }
}

int main() {
  int n, e;
  scanf("%d %d", &n, &e);
  reset(n);
  for (int i = 0; i < e; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    cost[u][v] = 1;
  }
  fowarshall(n);
  int queries;
  scanf("%d", &queries);
  while (queries--) {
    int u, v;
    scanf("%d %d", &u, &v);
    printf("%d\n", cost[u][v]);
  }
}