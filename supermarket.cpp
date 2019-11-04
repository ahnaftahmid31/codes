#include <bits/stdc++.h>
using namespace std;

const int N = 1003;

int cap, n, iter = 0;
int cost[N], weight[N];
int dp[N][N];

int knapsack(int i, int w) {
  iter++;
  if (i == 0) return 0;
  if (dp[i][w] != -1) return dp[i][w];
  dp[i][w] = knapsack(i - 1, w);
  if (w - weight[i] >= 0) {
    dp[i][w] = max(dp[i][w], cost[i] + knapsack(i - 1, w - weight[i]));
  }
  return dp[i][w];
}

int main() {
  int cases, caseno = 0;
  scanf("%d", &cases);
  while (cases--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d %d", cost + i, weight + i);
    }
    int members;
    scanf("%d", &members);
    vector<int> can_take;
    for (int i = 1; i <= members; i++) {
      int c;
      scanf("%d", &c);
      can_take.push_back(c);
    }
    int ans = 0;
    for (int i = 0; i < members; i++) {
      memset(dp, -1, sizeof(dp));
      cap = can_take[i];
      ans += knapsack(n, cap);
    }
    cout << ans << endl;
  }
}