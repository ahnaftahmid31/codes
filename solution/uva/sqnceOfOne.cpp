#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
  int a;
  while (scanf("%d", &a) != EOF) {
    int x = 0;
    ll ans = 0;
    while(true) {
      ans = (ans * 10 + 1) % a;
      x++;
      if (ans == 0) {
        break;
      }
    }
    printf("%d\n", x);
  }
  
}