#include <iostream>

int main() {
  int sqsum = 0;
  int sumsq = 0;
  for (int i = 1; i < 101; ++i) {
    sqsum += i;
    sumsq += i*i;
  } 
  std::cout << sqsum*sqsum - sumsq << std::endl;
  return 0;
}
