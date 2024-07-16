#include <iostream>
#include <string> 
#include <bitset>
#include <vector> 
int n; 
std::vector <std::string> a; 
std::bitset <3005> set_adj[3005]; 

int main () {
  std::cin >> n;
  a.resize(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (a[i][j] == '1') {
        set_adj[i][j] = 1; 
      }
    }
  }
  long long ans = 0LL; 
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (a[i][j] == '1') { 
        std::bitset <3005> common = set_adj[i] & set_adj[j]; 
        ans += common.count();
      } 
    }
  }
  std::cout << ans;
  return 0; 
}