#include <bits/stdc++.h>
using namespace std;

int main() {
  string str;
  cin >> str;
  int sz = str.size();
  bool flag = false;
  for (int i = 1; i < sz; i++) {
    if (str[i] == '1') {
      flag = true;
      break;
    }
  }
  int lost;
  if (sz == 1)
    lost = 0;
  else {
    if (flag)sz -= 1;
    else sz -= 2;
    lost = sz / 2 + 1;
  }
  cout << lost << endl;
}