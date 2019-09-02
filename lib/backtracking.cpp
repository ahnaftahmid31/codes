#include <bits/stdc++.h>
using namespace std;

const int n = 6;
int position[n + 1];
bool taken[n + 1];

void generate(int idx) {
  if (idx == n + 1) {
    for (int i = 1; i <= n; i++) {
      cout << position[i] << " ";
    }
    puts("");
    return;
  }

  for (int i = 1; i <= n; i++) {
    if (!taken[i]) {
      taken[i] = true;
      position[idx] = i;
      generate(idx + 1);
      taken[i] = false;
    }
  }
}

int main() {
  memset(taken, false, sizeof(taken));
  for (int i = 1; i <= n; i++) {
    position[i] = i;
  }
  generate(1);
}