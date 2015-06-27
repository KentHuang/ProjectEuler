#include <iostream>

using std::cout;

int sum_prop_div(int n) {
  int sum = 1;
  int i = 2;
  while (i < (n / i)) {
    if (n % i == 0) {
      sum += i;
      sum += n / i;
    }
    ++i;
  }
  return sum;
}

bool are_ami(int a, int b) {
  return a != b && a == sum_prop_div(b);
}

int main() {
  int sum = 0;
  for (int i = 0; i < 10000; ++i) {
    if (are_ami(i, sum_prop_div(i))) {
      sum += i;
      cout << sum << "\n";
    }
  }
  return 0;
}
