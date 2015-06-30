#include <iostream>
#include <fstream>
#include <string>


int main() {

  long maxProd = 0;

  int grid[20][20]; 
  std::string s;
  int count = 0;
  std::ifstream file ("euler11.txt");
  if (file.is_open()) {
    while (getline(file,s)) {
      do {
        grid[count/20][count%20] = std::stoi(s.substr((count%20)*3, 2));
        ++count;
      } while (count%20 != 0);
    }
    file.close();
  }

  for (int i = 0; i < 16; ++i) {
    for (int j = 0; j < 16; ++j) {
      long prod1 = grid[j][i] * grid[j+1][i+1] * grid[j+2][i+2] * grid[j+3][i+3]; 
      long prod2 = grid[j][i+3] * grid[j+1][i+2] * grid[j+2][i+1] * grid[j+3][i];
      maxProd = prod1 > maxProd ? prod1 : maxProd;
      maxProd = prod2 > maxProd ? prod2 : maxProd;
    }
  }

  for (int i = 0; i < 16; ++i) {
    for (int j = 0; j < 20; ++j) {
      long prod1 = grid[j][i] * grid[j][i+1] * grid[j][i+2] * grid[j][i+3];
      long prod2 = grid[i][j] * grid[i+1][j] * grid[i+2][j] * grid[i+3][j];
      maxProd = prod1 > maxProd ? prod1 : maxProd;
      maxProd = prod2 > maxProd ? prod2 : maxProd;
    }
  }

  std::cout << maxProd << std::endl;
  return 0;
} 
