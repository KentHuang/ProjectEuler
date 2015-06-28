#include <iostream>
#include <vector>

using namespace std;

vector<int> BigOne() {
  vector<int> one(999, 0);
  one.push_back(1); 
  return one;
}

int BigAdd(vector<int>& a, vector<int>& b) {
  int carry = 0;
  for (int i = a.size()-1; i != -1; --i) {
    int temp = a[i] + b[i] + carry;
    b[i] = temp % 10;
    carry = temp / 10;
  }
  return 0;
}

int main() {
  long index = 2;
  vector<int> fst = BigOne();
  vector<int> snd = BigOne();
  while (snd[0] == 0) {
    vector<int> temp = snd;
    BigAdd(fst, snd);
    fst = temp;
    ++index;
  }
  cout << index << endl;
  return 0;
}
