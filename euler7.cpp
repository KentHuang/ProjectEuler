#include <iostream>
#include <cmath>

const int max = 200000;

int main() {
  int bits[max] = {[0 ... (max-1)] = 1};
  bits[0] = bits[1] = 0;
  for (int i = 2; i < std::sqrt(max-1); ++i) {
    if (bits[i] == 1) {
      for (int j = i*i; j < max-1; j += i) {
        bits[j] = 0;
      }
    }
  }
 
  int count = 0;
  for (int i = 2; i < max; ++i) {
    if (bits[i] == 1) { ++count; }
    if (count  == 10001) { std::cout << i << std::endl; break; }
  }
  return 0;
}
