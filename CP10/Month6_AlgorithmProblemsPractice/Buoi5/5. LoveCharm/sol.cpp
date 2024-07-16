#include <iostream>
#include <string> 
#include <math.h> 
int f[2][12][12][3][2]; 
int n, k; 
std::string s; 
void updateMax(int &a, int b) {
  a = std::max(a, b); 
}         
int main () {
  int numTest;
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> k;
    std::cin >> s; 
    for (int i = 0; i <= 1; i++) {
      for (int changeK = 0; changeK <= k; changeK++) {
        for (int changeO = 0; changeO <= k; changeO++) {
          for (int diff = 0; diff <= 2; diff++) {
            for (int ch = 0; ch <= 1; ch++) {
              f[i][changeK][changeO][diff][ch] = -1; 
            } 
          }
        }
      }
    }
    f[1][s[0] == 'K'][0][1][0] = 0; 
    f[1][0][s[0] == 'O'][1][1] = 0; 
    for (int i = 1; i < n; i++) {
      int now = i % 2; 
      int nxt = !now; 
      for (int changeK = 0; changeK <= k; changeK++) {
        for (int changeO = 0; changeO <= k; changeO++) {
          for (int diff = 0; diff <= 2; diff++) {
            for (int ch = 0; ch <= 1; ch++) {
              f[nxt][changeK][changeO][diff][ch] = -1; 
            }
          }
        }
      }
      for (int changeK = 0; changeK <= k; changeK++) {
        for (int changeO = 0; changeO <= k; changeO++) {
          for (int diff = 0; diff <= 2; diff++) {
            for (int ch = 0; ch <= 1; ch++) {
              if (f[now][changeK][changeO][diff][ch] == -1) {
                continue; 
              }
              updateMax(f[nxt][changeK + (s[i] == 'K')][changeO][diff - (ch == 1)][0], f[now][changeK][changeO][diff][ch] + (ch == 1)); 
              updateMax(f[nxt][changeK][changeO + (s[i] == 'O')][diff + (ch == 0)][1], f[now][changeK][changeO][diff][ch] + (ch == 0)); 
            }
          }
        }
      }
    } 
    int ans = -2;
    for (int change = 0; change <= k; change++) {
      for (int diff = 1; diff <= 2; diff++) {
        for (int ch = 0; ch <= 1; ch++) {
          if (f[n % 2][change][change][diff][ch] == -1) {
            continue; 
          }
          int realDiff = diff - 1; 
          updateMax(ans, realDiff * f[n % 2][change][change][diff][ch]); 
        }
      }
    }
    std::cout << ans << std::endl;                                                                     
  }
  return 0; 
}
