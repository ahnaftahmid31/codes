#include <bits/stdc++.h>
using namespace std;

#define ll long long

// n ^ p % m = ((n ^ p/2 %m) * (n ^ p/2 % m)) %m
int c = 0;
ll bigMod(ll n, ll p, ll m) {
  c++; // counting how many steps needed

  if (p == 0) return 1; // n ^ 0 = 1 % m = 1
  if (p % 2 == 0) {
    ll mod = bigMod(n, p/2, m) % m;
    return  (mod * mod) % m;
  } 
  else {
    ll mod = bigMod(n, p - 1, m) % m;
    return ((n % m) * mod) % m;
  } 
}

// abcdefg = (abcdef * 10 + g) = ((abcde) * 10 + f) * 10 + g ...
ll bigIntMod(string str, ll m) {
  ll ans = 0;
  for (int j = 0; j<str.length(); j++) {
    int k = str[j] - '0';
    ans = (ans * 10 + k) % m;
  }
  ans = ans % m;
  return ans;
}

int main() {
  ll ans = bigIntMod("12131654651360312635465163103103615", 997);
  cout << ans  << endl;
}