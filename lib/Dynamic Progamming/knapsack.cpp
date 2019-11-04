#include <bits/stdc++.h>
using namespace std;

int cap, n;
int cost[100 + 5], weight[100 + 5];
vector<int> v;
int iter = 0;
int knapsack(int i, int w) {
  iter++;
  printf("%d %d\n", i, w);
  int profit1, profit2;
  if (n + 1 == i) return 0;
  if (weight[i] + w <= cap) {
    profit1 = cost[i] + knapsack(i + 1, w + weight[i]);
  } else
    profit1 = 0;
  profit2 = knapsack(i + 1, w);
  // printf("%d\n", max(profit1, profit2));
  return max(profit1, profit2);
}

int main() {
  cin >> n >> cap;
  for (int i = 1; i <= n; i++) {
    cin >> weight[i] >> cost[i];
  }
  cout << knapsack(1, 0) << endl;
  cout << iter<< endl;
}