#include <iostream>
#include <queue>
#include <string>
#include <vector>
std::priority_queue <int> pq; 

int main () {
  char c;  
  while (std::cin >> c) {
    if (c == '+') {
      int value = 0;
      std::cin >> value; 
      if ((int) pq.size() < 15000) {
        pq.push(value);
      }
    }
    else {
      if (pq.empty() == false) {
        int maxValue = pq.top(); 
        while (pq.empty() == false && pq.top() == maxValue) {
          pq.pop();
        }
      }
    }
  }
  std::vector <int> ans; 
  while (pq.empty() == false) {
    int maxValue = pq.top();  
    pq.pop();
    ans.push_back(maxValue); 
    while (pq.empty() == false && pq.top() == maxValue) {
      pq.pop();
    }
  }
  std::cout << (int) ans.size() << std::endl;
  for (int i = 0; i < (int) ans.size(); i++) {
    std::cout << ans[i] << std::endl;
  }
  return 0; 
}