#include <iostream>

using std::cout;
using std::endl;

const int LENGTH = 1000;

void multiplyByTwo(int *BigNum) {
  int carry = 0;
  for (int i = LENGTH-1; i >= 0; --i) {
    int ones = (BigNum[i] * 2) % 10;
    int tens = (BigNum[i] * 2) / 10;
    BigNum[i] = ones + carry;
    carry = tens;
  }
};

int main() {
  int two [LENGTH] = {};
  two[LENGTH-1] = 2;

  int n = 1;
  while (n != 1000) {
    multiplyByTwo(two); 
    ++n;
  }

  int sum = 0;
  for (int i = 0; i < LENGTH; ++i) {
    sum += two[i];
  }
  cout << sum << endl;

  return 0;
}
