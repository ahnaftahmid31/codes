#include <stdio.h>
#include <math.h>

int main()
{
  long long int n, next, son, magic, diff, a;
  int i, t;
  scanf("%d", &t);

  for (i = 1; i <= t; i++) {
    scanf("%lld", &n);
    a = sqrt(n);

    if (a * a == n) {
      next = n;
    }
    else {
      next = (a + 1) * (a + 1);
    }

    son = sqrt(next);
    magic = next - son + 1;

    if (n == magic) {
      printf("Case %d: %lld %lld\n", i, son, son);
    }
    else if (n > magic)
    {
      diff = n - magic;
      if (next % 2 != 0) {
        printf("Case %d: %lld %lld\n", i, son - diff, son);
      }
      else {
        printf("Case %d: %lld %lld\n", i, son, son - diff);
      }
    }
    else {
      diff = magic - n;
      if (next % 2 == 0) {
        printf("Case %d: %lld %lld\n", i, son - diff, son);
      }
      else {
        printf("Case %d: %lld %lld\n", i, son, son - diff);
      }
    }
  }
  return 0;
}
