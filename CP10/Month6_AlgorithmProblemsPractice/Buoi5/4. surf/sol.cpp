#include <iostream>
#include <math.h>
#include <vector>
struct wave {
  int start, wait, fun; 
};
int n; 
std::vector <int> listWave[2000005]; 
int f[2000005]; 
wave a[300005]; 

int main () {
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i].start >> a[i].fun >> a[i].wait;
    listWave[a[i].start + a[i].wait].push_back(i); 
  }
  for (int i = 0; i <= 2000000; i++) {
    f[i] = -1; 
  }
  f[0] = 0;
  for (int i = 1; i <= 2000000; i++) {
    f[i] = f[i - 1]; 
    for (int j = 0; j < (int) listWave[i].size(); j++) {
      int x = listWave[i][j]; 
      f[i] = std::max(f[i], f[a[x].start] + a[x].fun);
    }
  } 
  std::cout << f[2000000]; 
  return 0; 
}