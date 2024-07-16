#include <iostream>
#include <math.h>
int n, k;
long long a[1000005];
long long sum[1000005]; 
long long fMin[1000005], fMax[1000005];
const long long inf = 1000000000000007LL;  

int main () {
  std::cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    sum[i] = sum[i - 1] + a[i]; 
  }
  for (int i = 0; i < k; i++) {
    fMin[i] = inf; 
    fMax[i] = -1; 
  }
  for (int i = k; i <= n; i++) {
    fMin[i] = std::min(fMin[i - 1], sum[i] - sum[i - k]);
    fMax[i] = std::max(fMax[i - 1], sum[i] - sum[i - k]);  
  }
  long long ans = 0LL;
  for (int i = 2 * k; i <= n; i++) {
    ans = std::max(ans, std::max(std::abs(fMax[i - k] - (sum[i] - sum[i - k])), std::abs(sum[i] - sum[i - k] - fMin[i - k]))); 
  } 
  std::cout << ans;
  return 0; 
}
