#include <iostream>
#include <vector>
int n; 
int pre[100005]; 
int in[100005];
int position[100005]; 
int pos = 0; 
void solve(int l, int r) {
  pos++; 
  int x = position[pre[pos]]; 
  if (l < x) {
    solve(l, x - 1); 
  }
  if (x + 1 <= r) {
    solve(x + 1, r); 
  }
  std::cout << in[x] << ' ';
} 
 
int main () {
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> pre[i]; 
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> in[i]; 
    position[in[i]] = i; 
  }
  solve(1, n); 
  return 0; 
}