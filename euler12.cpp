#include <iostream>
#include <cmath>

int nTriNum(int n) {
  return (n+1)*n/2;
}

int numDivs(int n) {
  int count = 0;
  int sqrtn = std::sqrt(n);
  for (int i = 1; i < sqrtn; ++i) {
    if (n % i == 0) { ++count; }
  }
  if (floor(sqrtn) == sqrtn) {
    count = (count-1)*2 + 1;
  } else { count *= 2; }
  return count;
}

int main() {

  int count = 8;
  while (numDivs(nTriNum(count)) < 500) {
    ++count;
  }
  std::cout << nTriNum(count) << std::endl;
  return 0;
}
