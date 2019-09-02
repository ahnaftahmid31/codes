#include<bits/stdc++.h>
using namespace std;

template <class T>
T absolute(T x) {
  if (x < 0) return -x;
  else return x;
}

int main() {
  int a , b;
  a = 10;
  b = -10;
  cout << absolute(b) << endl;
}