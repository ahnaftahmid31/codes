#include <bits/stdc++.h>
using namespace std;

int cap, n;
int cost[100 + 5], weight[100 + 5];
int dp[100 + 5][100 + 5];

int iter = 0;

int knapsack(int i, int w) {
  iter++;
  printf("%d %d\n", i, w);
  if (n + 1 == i) return 0;
  int p1, p2, w2;
  w2 = w + weight[i];
  if (w2 <= cap) {
    if (!dp[i][w2]) dp[i][w2] = cost[i] + knapsack(i + 1, w2);
    p1 = dp[i][w2];
  } else
    p1 = 0;
  if (!dp[i + 1][w]) dp[i + 1][w] = knapsack(i + 1, w);

  p2 = dp[i + 1][w];
  return dp[i][w] = max(p1, p2);
}


int main() {
  cin >> n >> cap;
  for (int i = 1; i <= n; i++) {
    cin >> weight[i] >> cost[i];
  }
  cout << knapsack(1, 0) << endl;
  cout << iter << endl;
}