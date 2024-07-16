#include <iostream>
#include <utility>
#include <stack>

int a[30005];
int n; 
int numTest; 
std::pair <int, int> b[30005];

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i];
    }
    a[0] = 0; 
    a[n + 1] = 0;
    std::stack <int> st;
    st.push(0);
    for (int i = 1; i <= n; i++) {
      while (a[st.top()] >= a[i]) {
        st.pop();
      }
      b[i].first = st.top();
      st.push(i);
    }
    while (!st.empty()) {
      st.pop();
    }
    st.push(n + 1);
    for (int i = n; i >= 1; i--) {
      while (a[st.top()] >= a[i]) {
        st.pop();
      }
      b[i].second = st.top();
      st.push(i);
    }
    int position = -1; 
    int ans = -1; 
    for (int i = 1; i <= n; i++) {
      if (ans < a[i] * (b[i].second - 1 - b[i].first)) {
        ans = a[i] * (b[i].second - 1 - b[i].first);
        position = i;
      }
    }
    std::cout << ans << ' ' << b[position].first + 1 << ' ' << b[position].second - 1 << std::endl;
  } 
  return 0; 
}