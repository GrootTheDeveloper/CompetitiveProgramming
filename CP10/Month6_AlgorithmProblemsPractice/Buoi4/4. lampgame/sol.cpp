#include <iostream>
#include <queue> 
#include <utility>
#include <algorithm>
std::pair <int, int> a[200005];
int n;
std::priority_queue <int> pq;  

int main () {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i].first; 
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i].second; 
  }
  std::sort(a + 1, a + n + 1);
  long long ans = 0LL;  
  int maxTime = a[n].first; 
  int p = n; 
  while (maxTime > 0) {
    while (p > 0 && a[p].first >= maxTime) {
      pq.push(a[p].second); 
      p--; 
    }
    if (p == 0 && pq.empty() == true) {
      break; 
    }
    if (pq.empty() == false) {
      ans += pq.top();
      pq.pop();
    }
    else {
      maxTime = a[p].first; 
      continue;
    } 
    maxTime--; 
  }
  std::cout << ans;
  return 0; 
}