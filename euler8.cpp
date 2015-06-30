#include <iostream>
#include <istream>
#include <fstream>
#include <queue>

using namespace std;

long product(queue<int> q) {
  long prod = 1;
  while (!q.empty()) {
    prod *= q.front();
    q.pop();
  }
  return prod;
}

int main() {
  queue<int> buffer;  
  long maxProduct = 0;
  char c;
  ifstream file ("euler8.txt");
  if (file.is_open()) {
    while (buffer.size() != 12) {
      file.get(c); int p = (int)c - 48;
      if (p >= 0 && p <= 9) { buffer.push(p); }
    }
    do {
      int p = (int)c - 48;
      if (p >= 0 && p <= 9) { buffer.push(p); }
      else { continue; }
      long prod = product(buffer);
      if (prod > maxProduct) { maxProduct = prod; } 
      buffer.pop();
    } while (file.get(c));
    file.close();
  }
  std::cout << maxProduct << endl;
  return 0;
}

