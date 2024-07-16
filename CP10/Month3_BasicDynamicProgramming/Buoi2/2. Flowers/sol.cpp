#include <iostream> 
#include <math.h> 
const int inf = -1000000007; 
int cost[105][105]; 
int f[105][105]; 
int n, m; 
int ans[105]; 

int main () {
  std::cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      std::cin >> cost[i][j]; 
    }
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      f[i][j] = inf; 
    }
  }
  for (int j = 0; j <= m; j++) {
    f[0][j] = 0; 
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= m; j++) {
      f[i][j] = f[i - 1][j - 1] + cost[i][j];
      if (j - 1 >= i) {
        f[i][j] = std::max(f[i][j], f[i][j - 1]); 
      }
    }
  }
  std::cout << f[n][m] << std::endl;
  int i = n; 
  int j = m; 
  while (i > 0) {
    if (f[i][j] == f[i - 1][j - 1] + cost[i][j]) {
      ans[i] = j;
      i--;
      j--; 
    }
    else {
      j--; 
    }
  }
  for (int i = 1; i <= n; i++) {
    std::cout << ans[i] << ' ';
  }
  return 0; 
}