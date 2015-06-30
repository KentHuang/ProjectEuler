#include <iostream>


int main() {
  int k = 1;
  int sum = 0;
  while (k < 1000) {
    if (k % 3 == 0 || k % 5 == 0) {
      sum += k;  
    } 
    ++k;
  }
  std::cout << sum << std::endl;
  return 0;
}
