#include <iostream> 
int n;
int cnt[200005];  
long long ans = 0LL;
int main () {
  std::cin >> n;
  cnt[0] = 1; 
  int sum = 0; 
  for (int i = 1; i <= n; i++) {
    int value;
    std::cin >> value; 
    if (value < 0) {
      value += n * 10000; 
    }
    value %= n; 
    (sum += value) %= n;
    ans += cnt[sum]; 
    cnt[sum]++; 
  }
  std::cout << ans;
  return 0;
}