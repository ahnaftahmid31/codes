#include <bits/stdc++.h>
using namespace std;

int main() {
  int t, caseno = 0;
  long long time, x, y;

  cin >> t;
 
  while (t--) {
    scanf("%lld", &time);
    
    long long sqrt_time = sqrt(time);
    long long sq, sq_prev;
    // sq is the perfect_square of a certain row & column, you know sq_prev would be
    long long a, b, c;

    a = sqrt_time * sqrt_time;
    b = (sqrt_time + 1) * (sqrt_time + 1);
    c = (sqrt_time - 1) * (sqrt_time - 1);

    if(a == time) {
      sq = a;
      sq_prev = c;
    }
    else {
      sq = b;
      sq_prev = a;
    }
    long long k = sqrt(sq); 
    long long tt;

    tt = sq - time;

    //k is sqrt of sq
    if (k % 2 == 0) {
      if (tt < k) {
        x = k;
        y = tt + 1;
      }
      else {
        y = k;
        x = time - sq_prev;
      }
    }
    else {
      if (tt < k) {
        y = k;
        x = sq - time + 1;
      }
      else {
        x = k;
        y = time - sq_prev;
      }
    }
    printf("Case %d: %lld %lld\n", ++caseno, x, y);
  }
  return 0;
}