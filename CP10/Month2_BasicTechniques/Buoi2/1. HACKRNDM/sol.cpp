#include <iostream>
#include <algorithm>
int n;
long long k; 
long long a[100005]; 

int main () {
  std::cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i]; 
  }
  std::sort(a + 1, a + n + 1); 
  int ans = 0; 
  for (int i = 1; i < n; i++) {
    long long value = a[i] + k;
    int lo = i + 1;
    int hi = n;
    bool found = false;
    while (lo <= hi) {
      int mid = (lo + hi) / 2; 
      if (a[mid] == value) {
        found = true;
        break;   
      }
      else if (a[mid] < value) {
        lo = mid + 1; 
      }
      else {
        hi = mid - 1; 
      }
    }
    if (found == true) {
      ans++; 
    }  
  }
  std::cout << ans;
  return 0; 
}