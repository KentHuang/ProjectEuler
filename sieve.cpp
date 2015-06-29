#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

void sieve(int n) {
  int bits[n];
  for (int i = 0; i < n; ++i) { bits[i] = 1; }
  bits[0] = bits[1] = 0;
  for (int i = 2; i < std::sqrt(n); ++i) {
    if (bits[i] == 1) {
      for (int j = i*i; j < n; j += i) {
        bits[j] = 0;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    if (bits[i] == 1) { cout << i << endl; }
  }
}


int main() {
  sieve(1000);
  return 0;
}
