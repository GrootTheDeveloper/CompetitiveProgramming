#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <algorithm>
int f[3005][3005];
std::string s1, s2;
int len1, len2;

int main () {
  std::cin >> s1 >> s2;
  len1 = (int) s1.size();
  len2 = (int) s2.size();
  for (int i = 1; i <= len1; i++) {
    for (int j = 1; j <= len2; j++) {
      f[i][j] = std::max(f[i - 1][j], f[i][j - 1]);
      if (s1[i - 1] == s2[j - 1]) {
        f[i][j] = std::max(f[i][j], f[i - 1][j - 1] + 1);
      }
    }
  }
  std::vector <char> res;
  int i = len1;
  int j = len2;
  while (i > 0 && j > 0) {
    if (s1[i - 1] == s2[j - 1]) {
      res.push_back(s1[i - 1]);
      i--;
      j--;
    }
    else if (f[i][j] == f[i - 1][j]) {
      i--;
    }
    else {
      j--;
    }
  }
  std::reverse(res.begin(), res.end());
  for (int i = 0; i < (int) res.size(); i++) {
    std::cout << res[i];
  }
  return 0;
}