#include <iostream>
#include <cmath>

bool isPrime(int n) {
  if (n < 2) {
    return false;
  }
  for (int i = 2; i <= std::sqrt(n); ++i) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}


int main() {
  int max_primes, max_a, max_b = 0;
  for (int a = -999; a < 1000; ++a) {
    for (int b = -999; b < 1000; ++b) {
     int n = 0;
      while (isPrime(n*n+a*n+b)) {
        ++n;
      } 
      if (n > max_primes) {
        max_a = a;
        max_b = b;
        max_primes = n;
      }
    }
  }
  std::cout << max_a * max_b << std::endl;
  return 0;
}
