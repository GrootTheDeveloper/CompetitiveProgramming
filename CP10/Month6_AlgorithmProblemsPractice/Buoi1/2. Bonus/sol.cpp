#include <iostream> 
int sum[1005][1005]; 
int n, k; 

int main () {
  std::cin >> n >> k; 
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int x;
      std::cin >> x; 
      sum[i][j] = sum[i - 1][j] + sum[i][j - 1] + x - sum[i - 1][j - 1]; 
    }
  }
  int res = -1; 
  for (int i = 1; i <= n; i++) {
    if (i + k > n + 1) {
      break; 
    }
    for (int j = 1; j <= n; j++) {
      if (j + k > n + 1) {
        break; 
      }
      int x = i + k - 1; 
      int y = j + k - 1;
      int val = sum[x][y] - sum[i - 1][y] - sum[x][j - 1] + sum[i - 1][j - 1]; 
      if (res < val) {
        res = val; 
      }
    }
  }
  std::cout << res; 
  return 0;
}
