#include <bits/stdc++.h>
using namespace std;

#define ll long long

// n ^ p % m = ((n ^ p/2 %m) * (n ^ p/2 % m)) %m
ll bigMod(ll n, ll p, ll m) {

  if (p == 0) return 1;  // n ^ 0 = 1 % m = 1
  if (p % 2 == 0) {
    ll mod = bigMod(n, p / 2, m) % m;
    return (mod * mod) % m;
  } else {
    ll mod = bigMod(n, p - 1, m) % m;
    return ((n % m) * mod) % m;
  }
}

int main() {
  ll b, p, m;
  while (scanf("%lld %lld %lld", &b, &p, &m) != EOF) {
    printf("%lld\n", bigMod(b, p, m));
  }
}

