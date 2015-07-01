#include <iostream>
#include <fstream>
#include <string>

using std::string;

int ctoi(char c) {
  return (int)c - 48;
}

char itoc(int i) {
  return (char)(i + 48);
}

void BigAdd(string& acc, string n) { 
  acc = "0" + acc; //padding
  while (acc.size() > n.size()) { n = "0" + n; }

  int carry = 0;
  for (int i = acc.size()-1; i > -1; --i) {

    int temp  = ctoi(acc[i]) + ctoi(n[i]) + carry ;
    acc[i] = itoc( temp % 10 );
    carry  = temp / 10;
  }
  if (acc[0] == '0') { acc = acc.substr(1, acc.size()-1); }
}

int main() {
  string num;
  string sum;
  char c;
  std::ifstream file ("euler13.txt");
  if (file.is_open()) {
    getline(file, sum);
    while (getline(file, num)) {
      BigAdd(sum, num);
    }
    file.close();
  }
  std::cout << sum.substr(0, 10) << std::endl;
  return 0;
}
