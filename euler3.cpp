#include <iostream> 
#include <cmath>

// returns smallest divisor 
long find_divisor(long& n) {
  if (n == 1) { return 1; }
  for (long i = 2; i < std::sqrt(n); ++i) {
    if (n % i == 0) { 
      n /= i;
      return i; 
    }
  }
  long temp = n;
  n = 1;
  return temp;
}

int main() {
  long num = 600851475143;
  long max_prime = 0;
  while (num != 1) {
    long d = find_divisor(num);
    if (d > max_prime) max_prime = d;
  }
  std::cout << max_prime << std::endl;
  return 0;
}
