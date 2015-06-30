#include <iostream>
#include <cmath>

const int m = 2000000;

int main() {
  int bits[m] = {[0 ... m-1] = 1};
  bits[0] = bits[1] = 0;
  for (int i = 2; i < std::sqrt(m); ++i) {
    if (bits[i] == 1) {
      for (int j = i*i; j < m; j += i) {
        bits[j] = 0;
      }
    }
  }
  long sum = 0;
  for (int i = 2; i < m; ++i) {
    if (bits[i] == 1 && i < m) { sum += i; }
  }
  std::cout << sum << std::endl;
  return 0;
}
