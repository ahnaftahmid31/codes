#include<bits/stdc++.h>
using namespace std;

const int N = 100;

int ara[N] = {1, 2, 3, 4, 5, 6, 7, 8};

int binary_search(int left, int right, int x) {
  int mid = left + (right - left) / 2;
  if (right >= left) {
    if (ara[mid] < x)  return binary_search(mid + 1, right, x);
    else if (ara[mid] == x)  return mid;
    else if (ara[mid] > x) return binary_search(left, mid - 1, x);
  }
  return -1;
}

int main() {
  int x = 10;
  int ans = binary_search(0, 7, x);
  cout << ans << endl;
}