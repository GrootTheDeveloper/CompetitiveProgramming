#include <iostream> 
#include <math.h>
int height[1000005]; 
int n, M, maxHeight = -1; 

int main () {
  std::ios_base::sync_with_stdio(false); 
  std::cin >> n >> M;
  for (int i = 1; i <= n; i++) {
    std::cin >> height[i];
    maxHeight = std::max(maxHeight, height[i]);
  }
  int lo = 0;
  int hi = maxHeight;
  int ans = -1; 
  while (lo <= hi) {
    int mid = (lo + hi) / 2; 
    int limWood = M; 
    bool ok = false;
    for (int i = 1; i <= n; i++) {
      int collect = std::max(0, height[i] - mid); 
      if (limWood <= collect) {
        ok = true; 
        break; 
      }
      limWood -= collect; 
    }
    if (ok == true) {
      ans = mid; 
      lo = mid + 1; 
    }
    else {
      hi = mid - 1; 
    }
  }
  std::cout << ans;
  return 0; 
}