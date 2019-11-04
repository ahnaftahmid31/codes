//uva 10684 max-sub-array The Jackpot
#include <bits/stdc++.h>
using namespace std;

const int N = 10004;

int main() {
  int n, ara[N], local, global;
  while (scanf("%d", &n) and n) {
    local = 0, global = 0;
    for (int i = 0; i < n; i++) scanf("%d", ara + i);
    for (int i = 0; i < n; i++) {
      local = max(ara[i], ara[i] + local);
      global = max(local, global);
    }
    if (global)
      printf("The maximum winning streak is %d.\n", global);
    else
      printf("Losing streak.\n");
  }
}
