#include <iostream> 
#include <algorithm>
#include <math.h>
int s[100005]; 
int n, l, a, b;
int numTest; 

long long f(long long position) {
  long long ret = 0LL; 
  for (int i = 1; i <= n; i++) {
    ret += 1LL * std::abs(s[i] - position); 
    position += l; 
  }
  return ret; 
}

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> l >> a >> b;
    for (int i = 1; i <= n; i++) {
      std::cin >> s[i];
    }
    std::sort(s + 1, s + n + 1); 
    long long ans = 100000000000000007LL; 
    long long lo = a;
    long long hi = b - n * l; 
    while (lo <= hi) {
      long long u = lo + (hi - lo) / 3;
      long long v = hi - (hi - lo) / 3; 
      long long fu = f(u);
      long long fv = f(v); 
      if (fu > fv) {
        ans = std::min(ans, fv); 
        lo = u + 1;     
      }
      else {
        ans = std::min(ans, fu); 
        hi = v - 1; 
      }
    }
    std::cout << ans << std::endl; 
  }
  return 0; 
}