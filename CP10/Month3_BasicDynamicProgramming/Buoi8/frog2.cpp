#include <iostream>
#include <math.h> 
int f[100005];
int height[100005];
int n, k;

int main () {
  std::cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    std::cin >> height[i];
  }
  for (int i = 0; i <= n; i++) {
    f[i] = 1000000007;
  }
  f[1] = 0;
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= std::min(i - 1, k); j++) {
      f[i] = std::min(f[i], f[i - j] + std::abs(height[i] - height[i - j]));
    }
  }
  std::cout << f[n];
  return 0;
}