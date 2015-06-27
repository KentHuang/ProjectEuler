#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>

using namespace std;

int sum_divisors(int n) {
  int sum = 1;
  int i = 2;
  while (i <= sqrt(n)) {
    if (n % i == 0) {
      sum += i;
        if (i != (n / i)) {
          sum += n / i;
        }
    }
    ++i;
  }
  return sum;
}

bool is_abundant(int n) {
  return sum_divisors(n) > n;
}



int main() {
  vector<int> abund_nums;
  for (int i = 12; i < 28123; ++i) {
    if (is_abundant(i)) {
      abund_nums.push_back(i);
    }
  }

  set<int> sum2abund_nums;
  for (vector<int>::const_iterator iter1 = abund_nums.begin();
       iter1 != abund_nums.end(); ++iter1) {
    for (vector<int>::const_iterator iter2 = abund_nums.begin();
         iter2 != abund_nums.end(); ++iter2) {
      int s = (*iter1) + (*iter2);
      if (s <= 28123) {
        sum2abund_nums.insert(s);
      } else {
        break;
      }
    }
  }

  int sum = 0;
  for (int i = 1; i <= 28123; ++i) {
    if (find(sum2abund_nums.begin(), sum2abund_nums.end(), i) == sum2abund_nums.end()) {
      sum += i;
    }
  }
  cout << "The sum is: " << sum << endl;
  return 0;
}


