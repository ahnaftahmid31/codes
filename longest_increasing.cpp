#include <bits/stdc++.h>
using namespace std;

#define inf 1 << 29
const int N = 100005;

int ara[N] = {0};

int fast_lis(int n) {
  int d[N];
  d[0] = -inf;
  for (int i = 1; i <= n; i++) d[i] = inf;
  for (int i = 0; i < n; i++) {
    int j = upper_bound(d, d + n, ara[i]) - d;
    if (d[j - 1] < ara[i] && ara[i] < d[j]) d[j] = ara[i];
  }
  int mx = 0;
  for (int i = 1; d[i] < inf && i <= n; i++) {
    printf("%d ", d[i]);
    mx = i;
  }
  puts("");
  return mx;
}


int lis(int n) {
  int d[N] = {1}, path[N] = {-1}, mx = 0, mxi;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (ara[j] < ara[i]) {
        if (d[j] + 1 > d[i]) {
          d[i] = d[j] + 1;
          path[i] = j;
          if (d[i] > mx) {
            mx = d[i];
            mxi = i;
          }
        }
      }
    }
  }
  int i = mxi;
  while (i != -1) {
    printf("%d ", ara[i]);
    i = path[i];
  }
  puts("");
  return mx;
}


int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", ara + i);
  cout << fast_lis(n) << endl;
}