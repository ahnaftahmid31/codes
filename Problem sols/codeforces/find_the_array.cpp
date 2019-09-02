#include <bits/stdc++.h>
using namespace std;

int getLowest(int n, int l) {
  int sum, k, i;
  for (i = 1, sum = 0, k = 1; i <= l; i++, k *= 2) {
    sum += k;
  }
	int xtra = n - l;
	sum = sum + xtra;
	return sum;
}

int getHighest(int n, int r) {
  int sum, k, i;
  for (i = 1, sum = 0, k = 1; i <= r; i++, k *= 2) {
    sum += k;
  }
  k /= 2;
	int xtra = (n - r) * k;
  sum = sum + xtra;
  return sum;
}

int main() {
  int l, r, n;
  scanf("%d %d %d", &n, &l, &r);
  int low = getLowest(n, l);
  int high = getHighest(n, r);
  printf("%d %d\n", low, high);
}
