#include <iostream>
#include <map>

using std::cout;
using std::endl;

long rule(long n) {
  if (n % 2 == 0) { n /= 2; }
  else { n = 3*n + 1; }
  return n;
}

int chain(std::map<long, int> table, long n, int count) {
  return 0; 
}

int main() {

  int maxLength = 0;
  long maxNumber = 0;
  std::map<long, int> table; 
  table[1] = 1;

  for (long i = 2; i < 1000000; ++i) {
    long count = 1;
    long n = i;
    while (table[i] == 0) {
      n = rule(n);
      if (table[n] != 0) {
        count += table[n];
        table[i] = count;
      } else { ++count; }
    }
    if (count > maxNumber) {maxNumber = count; maxNumber = i;}
  }
  cout << maxNumber << endl;
  /*
  for (std::map<long, int>::const_iterator iter = table.begin();
       iter != table.end(); ++iter) {
    std::cout << iter->first << ":" << iter->second << std::endl;
  }
  */
  return 0;
}
