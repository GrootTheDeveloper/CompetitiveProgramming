#include <iostream> 
int n, h;
int a[1005];

int main () {
  std::cin >> n >> h;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] <= h) {
      ans++;  
    }
    else {
      ans += 2; 
    }
  }
  std::cout << ans; 
  return 0; 
}