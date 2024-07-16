#include <iostream>
#include <bitset>
int n;
int a[1005][1005];
std::bitset <1005> win[1005], lose[1005];

int main () {
  std::cin >> n; 
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      std::cin >> a[i][j];
      if (a[i][j] == 1){
        win[i].set(j);
        lose[j].set(i);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (a[i][j] == 0) {
        continue; 
      }
      std::bitset <1005> tmp = win[j] & lose[i]; 
      if (tmp.count() == 0) {
        continue; 
      }
      for (int k = 1; k <= n; k++) {
        if (tmp[k] == 1) {
          std::cout << i << ' ' << j << ' ' << k;
          return 0;
        }
      }
    }
  }
  std::cout << "-1 -1 -1";
  return 0; 
}