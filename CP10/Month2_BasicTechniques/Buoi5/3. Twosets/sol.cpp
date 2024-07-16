#include <iostream>
#include <vector> 
int main () {
  long long n; 
  std::cin >> n; 
  long long sum = n * (n + 1) / 2;
  if (sum % 2 == 1) {
    std::cout << "NO"; 
  } 
  else {
    std::cout << "YES" << std::endl; 
    long long half = sum / 2; 
    std::vector <int> saveFirst, saveSecond; 
    for (int i = n; i >= 1; i--) {
      if (i <= half) {
        saveFirst.push_back(i);
        half -= i; 
      }
      else {
        saveSecond.push_back(i); 
      }
    }
    std::cout << (int) saveFirst.size() << std::endl; 
    for (int i = 0; i < (int) saveFirst.size(); i++) {
      std::cout << saveFirst[i] << ' '; 
    }
    std::cout << std::endl;
    std::cout << (int) saveSecond.size() << std::endl; 
    for (int i = 0; i < (int) saveSecond.size(); i++) {
      std::cout << saveSecond[i] << ' '; 
    }
  }
  return 0;
}