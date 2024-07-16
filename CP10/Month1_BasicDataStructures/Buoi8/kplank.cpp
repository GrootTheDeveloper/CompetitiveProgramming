#include <iostream>
#include <math.h> 
#include <stack>
int n;
int a[1000005]; 
int Left[1000005], Right[1000005];
std::stack <int> mystack; 

int main () {
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i]; 
  }
  mystack.push(0); 
  for (int i = 1; i <= n; i++) {
    while (a[mystack.top()] >= a[i]) {
      mystack.pop(); 
    }
    Left[i] = mystack.top();
    mystack.push(i); 
  }
  while (mystack.empty() == false) {
    mystack.pop(); 
  }
  mystack.push(n + 1);
  for (int i = n; i >= 1; i--) {
    while (a[mystack.top()] >= a[i]) {
      mystack.pop();
    }
    Right[i] = mystack.top();
    mystack.push(i); 
  }
  int ans = 1; 
  for (int i = 1; i <= n; i++) {
    if (a[i] <= Right[i] - Left[i] - 1) {
      ans = std::max(ans, a[i]);
    }
  }
  std::cout << ans; 
  return 0; 
}