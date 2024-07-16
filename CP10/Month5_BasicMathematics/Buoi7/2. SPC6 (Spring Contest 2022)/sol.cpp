#include <iostream>
#include <algorithm>
#include <math.h>

int main () {
  int numTest;
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int n, m;
    std::cin >> n >> m;
    std::cout << (std::__gcd(n, m) == 1 ? "CORRECT" : "INCORRECT") << std::endl;
  }
  return 0;
}