#include <iostream>
#include <fstream>
#include <string>




/*
int main() {
  int grid[5][5];
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 5; ++j) {
      grid[j][i] = i*j;
      std::cout << grid[j][i];
    }
  }

  return 0;
}
*/

int main() {

  int grid[20][20]; 
  char c[4];
  int maxSum = 0;
      std::cout << "gothere1" << std::endl;
  std::ifstream file ("euler11.txt");
      std::cout << "gothere2" << std::endl;
  if (file.is_open()) {
    std::cout << "gothere3" << std::endl;
    for (int i = 0; i < 20; ++i) {
      for (int j = 0; j < 20; ++j) {
        std::cout << "gothere4" << std::endl;
        if (file.get(c, 4)) {    
          std::cout << "gothere5" << std::endl;
          try {
          //std::cout << ":" << (std::string)c << ":";
            grid[j][i] = std::stoi(c);
          //std::cout << grid[j][i] << ":";
          } catch(const std::exception& e) { 
            std::cout << e.what() << " omg" << std::endl;}
        }
      }
    }

    for (int i = 0; i < 16; ++i) {
      for (int j = 0; i < 16; j++) {
        int sum = grid[j][i] + grid[j+1][i+1] + grid[j+2][i+2] + grid[j+3][i+3]; 
        if (sum > maxSum) { maxSum = sum; }
      }
    }
    file.close();
  }
  std::cout << maxSum << std::endl;
  return 0;
} 
