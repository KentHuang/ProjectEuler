#include <iostream>
#include <map>

using std::cout;
using std::endl;

long rule(long n) {
  if (n % 2 == 0) { n /= 2; }
  else { n = 3*n + 1; }
  return n;
}

int chain(std::map<long, int>& table, long n, int count) {
  if (table[n] != 0) { 
    return table[n];
  }
  else {
    long next = rule(n); 
    return table[n] = count + chain(table, next, count); 
  }
}

int main() {

  std::map<long, int> table; 
  table[1] = 1;

  long maxNumber;
  long maxCount = 0;  
  for (long i = 2; i < 1000000; ++i) {
    int n = i;
    chain(table, n, 1); 
    if (table[i] > maxCount) { maxCount = table[i]; maxNumber = i; }
  }
 
  cout << maxNumber << endl;
  return 0;
}
