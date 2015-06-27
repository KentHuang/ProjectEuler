#include <iostream>
#include <string>
#include <algorithm>


using namespace std;


int main() {
  string s = "0123456789";
  int i = 1;
  while (i < 1000000) {
    next_permutation(s.begin(), s.end()); 
    i++;
  }
  cout << s << endl;
  return 0;
}
