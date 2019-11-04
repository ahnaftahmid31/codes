#include <bits/stdc++.h>
using namespace std;

vector<long long> sqrValue;
long long currentMax = 0;

int main() {
  int t, caseno = 0;
  long long s, x, y;

  cin >> t;
  sqrValue.push_back(0);

  while (t--) {
    scanf("%lld", &s);
    while (currentMax < s) {
      long long temp = sqrValue.size();
      currentMax = temp * temp;
      sqrValue.push_back(currentMax);
    }

    long long k, tt;
    for (k = 1; k < sqrValue.size(); ++k) {
      if (sqrValue[k] >= s)
        break;
    }

    tt = sqrValue[k] - s;

    if (k % 2 == 0) {
      if (tt < k) {
        x = k;
        y = tt + 1;
      }
      else {
        y = k;
        x = s - sqrValue[k - 1];
      }
    }
    else {
      if (tt < k) {
        y = k;
        x = sqrValue[k] - s + 1;
      }
      else {
        x = k;
        y = s - sqrValue[k - 1];
      }
    }

    printf("Case %d: %lld %lld\n", ++caseno, x, y);
  }

  return 0;
}