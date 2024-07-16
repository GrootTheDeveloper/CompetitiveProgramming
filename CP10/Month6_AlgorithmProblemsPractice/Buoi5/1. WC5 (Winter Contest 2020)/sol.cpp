#include <iostream>
#include <string>
int numTest; 
std::string s1, s2; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> s1 >> s2;
    s1.pop_back();
    s2.pop_back();
    s2.pop_back();
    std::cout << s1 << s2 << std::endl;
  }
  return 0; 
}