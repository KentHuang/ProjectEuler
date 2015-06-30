#include <iostream>

int main() {
  int sum = 0;
  int fst = 1;
  int snd = 2;
  while (snd < 4000000) {
    if (snd % 2 == 0) {
      sum += snd;
    }
    int temp = snd;
    snd += fst;
    fst = temp;
  }
  std::cout << sum << std::endl;
  return 0;
}
