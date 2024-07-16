#include <iostream> 
int a[200005]; 
int n; 
 
int main () {
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i]; 
  }
  long long ans = 0LL; 
  for (int i = 2; i <= n; i++) {
    if (a[i] < a[i - 1]) {
      ans += a[i - 1] - a[i]; 
      a[i] = a[i - 1];
    }   
  }
  std::cout << ans;
  return 0;
}