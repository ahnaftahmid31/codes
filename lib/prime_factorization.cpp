#include <bits/stdc++.h>
using namespace std;

const int P = 1505;

vector<int> primes;
vector<int> factors[P];
bool is_prime[P];

void sieve(int n) {
  memset(is_prime, true, sizeof(is_prime));
  is_prime[1] = false;
  int sqr = sqrt(n);

  for (int i = 2; i <= sqr; i++) {
    if (!is_prime[i]) continue;
    for (int j = 2; i * j <= n; j++) {
      is_prime[i * j] = false;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (is_prime[i]) {
      primes.push_back(i);
    }
  }
  
}

void prime_factor_gen_fast(int n) {  
  // I think it is fast and I can store powers of
  //  prime factors                                  
  for (int num = 1; num <= n; num++) {
    int k = num;
    int sqt = sqrt(k);
    for (int i = 0; primes[i] <= sqt; i++) {
      int p = primes[i];
      if (k % p != 0) continue;
      while (k % p == 0) {
        k = k / p;
      }
      factors[num].push_back(p);
      if (!is_prime[k]) continue;
      if (k * k == num) continue;
      factors[num].push_back(k);
      break;
    }
  }
}

// naive approach for storing prime factors
void prime_factor_gen(int n) { 
  
  for (int num = 1; num <= n; num++) {
    int half = num / 2;
    for (int i = 0; primes[i] <= half; i++) {
      if (num % primes[i] == 0) {
        factors[num].push_back(primes[i]);
      }
    }
  }
}

// this function generates factors within sieve 
void sieve_factor() { 
  bool p[1005];
  int half = 500;
  memset(p, true, sizeof(p));
  p[1] = false;
  for (int i = 2; i <= half; i++) {
    if (!p[i]) continue;
    for (int j = 2; j * i <= 1000; j++) {
      p[i * j] = false;
      factors[j * i].push_back(i);
    }
  }
}

int main() {
  sieve(1005);
  prime_factor_gen_fast(1005);

  int number = 0;
  while (true) {
    ++number;
    if ( number == 1000) break;
    cout << "factors of " << number << " are: ";
    if (factors[number].size() == 0) cout << "none\n";
    for (int i = 0; i < factors[number].size(); i++) {
      cout << factors[number][i] << " ";
    }
    cout << endl;
  }
}