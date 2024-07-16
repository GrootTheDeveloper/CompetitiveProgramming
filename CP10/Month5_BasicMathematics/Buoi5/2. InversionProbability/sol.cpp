#include <iostream>
#include <iomanip>
int n;
int r[105]; 
int sum(int x) {
  return x * (x - 1) / 2; 
}
 
int main () {
  long double ans = 0.0; 
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> r[i]; 
  }
  for (int i = 1; i < n; i++) {
    for (int j = i + 1; j <= n; j++) {
      int numbInversions = (r[i] <= r[j] ? sum(r[i]) : sum(r[j]) + (r[i] - r[j]) * r[j]); 
      ans += (long double) numbInversions / (r[i] * r[j]); 
    }
  }
  std::cout << std::fixed << std::setprecision(6) << (double) ans;
  return 0; 
}