#include <iostream> 
const long long mod = 1000000007;
long long fact[100005], invFact[100005];
int n, k, numTest;  
 
long long fastpow(const long long x, long long n) {
  if (n == 0) {
    return 1LL; 
  }
  long long ret = fastpow(x, n / 2); 
  (ret *= ret) %= mod; 
  if (n % 2 == 1) {
    (ret *= x) %= mod; 
  }
  return ret; 
}
 
void init() {
  fact[0] = 1LL; 
  invFact[0] = 1LL;
  for (int i = 1; i <= 100005; i++) {
    fact[i] = (fact[i - 1] * (long long) i) % mod; 
    invFact[i] = fastpow(fact[i], mod - 2); 
  }
}
 
long long C(int n, int k) {
  long long ret = fact[n]; 
  (ret *= invFact[n - k]) %= mod;
  (ret *= invFact[k]) %= mod;
  return ret;  
}
 
int main () {
  init(); 
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> k; 
    std::cout << C(n, k) << std::endl;
  }
  return 0;
}