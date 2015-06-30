#include <iostream>
#include <cmath>

int main() {
  for (int a = 1; a < 1000; ++a) {
    for (int b = 1; b < 1000; ++b) {
      float c = std::sqrt(a*a+b*b);
      if (ceilf(c) == c && a+b+((int)c) == 1000) {
        std::cout << a*b*((int)c) << std::endl;
        return 0;
      }
    }
  }
  return 0;
}
