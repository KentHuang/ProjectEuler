#include <iostream>
#include <string>

bool isPalindrome(std::string s) {
  if (s.size() == 1 || s == "") { return true; }
  return (s[0] == s[s.size()-1]) && isPalindrome(s.substr(1, s.size()-2));
}

int main() {
  int max = 0;
  for (int a = 999; a != 99; --a) {
    for (int b = 999; b != 99; --b) {
      if (isPalindrome(std::to_string(a*b)) && a*b > max) { 
        max = a*b;
      }
    }
  }
  std::cout << max << std::endl; 
  return 0;
}
