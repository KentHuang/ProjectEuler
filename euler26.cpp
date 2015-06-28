#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;



int main() {

  int max = 0;
  const int max_its = 100;

  for (int d = 2; d < 10; ++d) {
    vector<int> result;
    int i = 10;
    while ((result.size() < max_its) && (i != 0)) {
      int k = 1;
      while ((i - k * d) >= 0) {
        ++k;
      }
      i = (i - (--k * d)) * 10;
      result.push_back(k);
    }
    
    if (result.size() < max_its) {
      continue;
    }    

    for(int i = 0; i < result.size(); ++i) {
      cout << result[i];
    }
    cout << "\n" << endl;
  }

  return 0;
}
