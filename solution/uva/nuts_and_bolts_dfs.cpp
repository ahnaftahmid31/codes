#include<bits/stdc++.h>
using namespace std;

#define N 1003

int nuts, bolts, used[N], dibs[N];
int fits[N][N];  // <-- edmond's matrix

bool dfs(int u) {
  for(int i = 1; i<= nuts; i++) {
    if(fits[u][i] && !used[i]) {
      used[i] = true;

      if(dibs[i] < 0 || dfs(dibs[i])) { dibs[i] = u; return true; }
    }
  }
  return false;
}

int maxfit() {
  int max_fits = 0;
  memset(dibs, -1, sizeof(dibs));

  for(int b = 1; b <= bolts; b++) {
    memset(used, false, sizeof(used));
    if(dfs(b)) max_fits++;
  }
  return max_fits;
}

int main() {
  int cases;
  scanf("%d", &cases);
  
  for (int i = 1; i <= cases; i++) {
    scanf("%d %d", &bolts, &nuts);
    memset(fits, 0, sizeof(fits));

    for (int b = 1; b <= bolts; b++) {
      for (int n = 1; n <= nuts; n++) {
        scanf("%d", &fits[b][n]);
      }
    }
    printf("Case %d: a maximum of %d nuts and bolts can be fitted together\n", i, maxfit());
  }
  return 0;
}
