#include <iostream> 
long long a[200005]; 
int n, k; 

int main () {
  std::cin >> n >> k; 
  long long maxValue = 0LL; 
  long long total = 0LL; 
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    total += a[i]; 
    if (maxValue < a[i]) {
      maxValue = a[i]; 
    } 
  }
  long long lo = maxValue; 
  long long hi = total; 
  long long ans = 0LL; 
  while (lo <= hi) {
    long long mid = (lo + hi) / 2; 
    int numbArray = 0; 
    long long sum = 0LL;  
    for (int i = 1; i <= n; i++) {  
      sum += a[i]; 
      if (sum > mid) {
        numbArray++; 
        sum = a[i];
      }
    }
    numbArray++;
    if (numbArray > k) {
      lo = mid + 1; 
    }
    else {
      ans = mid; 
      hi = mid - 1; 
    }
  }
  std::cout << ans;
  return 0; 
}