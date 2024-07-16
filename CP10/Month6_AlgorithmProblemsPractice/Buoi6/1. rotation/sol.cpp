#include <iostream>

int main () {
  int n;
  int ans = 0; 
  std::cin >> n; 
  for (int i = 1; i < n; i++) {
    int start, finish, type;
    std::cin >> start >> finish >> type;
    ans += type; 
  }
  std::cout << ans % 2; 
  return 0; 
}