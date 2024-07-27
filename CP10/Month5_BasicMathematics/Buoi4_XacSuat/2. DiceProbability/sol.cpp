#include <iostream>
#include <iomanip>
 
double f[105][605]; 
 
int main () {
  int n, a, b;
  std::cin >> n >> a >> b;
  f[0][0] = 1.0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= 6 * i; j++) {
      if (f[i][j] == 0.0) {
        continue; 
      }
      for (int x = 1; x <= 6; x++) {
        f[i + 1][j + x] += f[i][j] * 1.0 / 6.0; 
      }
    }
  } 
  double ans = 0.0; 
  for (int i = a; i <= b; i++) {
    (ans += f[n][i]); 
  }
  std::cout << std::fixed << std::setprecision(6) << ans; 
  return 0; 
}