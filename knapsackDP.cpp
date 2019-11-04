#include <bits/stdc++.h>
using namespace std;

int cap, n;
int cost[100 + 5], weight[100 + 5];
int dp[100 + 5][100 + 5];

int iter = 0;

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
  memset(dp, -1, sizeof(dp));
  cin >> n >> cap;
  for (int i = 1; i <= n; i++) {
    cin >> weight[i] >> cost[i];
  }
  cout << knapsack(n, cap) << endl;
  cout << iter << endl;
}