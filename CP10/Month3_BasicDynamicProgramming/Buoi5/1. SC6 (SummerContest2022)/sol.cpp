#include <iostream> 
#include <math.h> 
const int inf = -1000000007; 
int n, k, numTest; 
int a[10005]; 
int f[10005][205][3][3];

int multiple(const int &prevState, const int &curState) {
  if (prevState == 0) {
    if (curState == 1) {
      return 1; 
    }
    else {
      return -1; 
    }
  }
  if (prevState == 1) {
    if (curState == 0) {
      return -1; 
    }
    else if (curState == 1) {
      return 0; 
    }
    else {
      return -2; 
    }
  }
  else {
    if (curState == 0) {
      return 1; 
    }
    else if (curState == 1) {
      return 2; 
    }
    else {
      return 0; 
    }
  }
} 

void updateMax(int &a, int b) {
  a = std::max(a, b); 
}

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> k; 
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i]; 
    }
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= k; j++) {
        for (int prevState = 0; prevState <= 2; prevState++) {
          for (int curState = 0; curState <= 2; curState++) {
            f[i][j][prevState][curState] = inf; 
          }
        }
      }
    }
    f[1][1][0][1] = a[1]; 
    f[1][1][0][2] = -a[1]; 
    for (int i = 1; i < n; i++) {
      for (int j = 1; j <= k; j++) {
        for (int prevState = 0; prevState <= 2; prevState++) {
          for (int curState = 0; curState <= 2; curState++) {
            if (f[i][j][prevState][curState] == inf) {
              continue; 
            }
            updateMax(f[i + 1][j][prevState][curState], f[i][j][prevState][curState] + multiple(prevState, curState) * a[i + 1]);
            if (j == k - 1) {
              updateMax(f[i + 1][j + 1][curState][0], f[i][j][prevState][curState] + multiple(curState, 0) * a[i + 1]); 
            } 
            else if (j < k - 1) {
              for (int nextState = 1; nextState <= 2; nextState++) {
                updateMax(f[i + 1][j + 1][curState][nextState], f[i][j][prevState][curState] + multiple(curState, nextState) * a[i + 1]); 
              }  
            }
          }
        }
      }
    }
    int ans = inf; 
    for (int prevState = 1; prevState <= 2; prevState++) {
      updateMax(ans, f[n][k][prevState][0]); 
    }
    std::cout << ans << std::endl; 
  }
  return 0; 
}