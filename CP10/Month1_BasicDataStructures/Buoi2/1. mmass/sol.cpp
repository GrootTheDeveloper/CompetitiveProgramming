#include <iostream>
#include <stack>
#include <string>
std::string chemistry; 

int main () {
  std::cin >> chemistry; 
  std::stack <int> mystack; 
  for (int i = 0; i < (int) chemistry.size(); i++) {
    if (chemistry[i] == '(') {
      mystack.push(0); 
    }
    else if (chemistry[i] == 'C') {
      mystack.push(12);
    } 
    else if (chemistry[i] == 'H') {
      mystack.push(1); 
    }
    else if (chemistry[i] == 'O') {
      mystack.push(16); 
    }
    else if (chemistry[i] == ')') {
      int sum = 0; 
      while (true) {
        int value = mystack.top();             
        mystack.pop(); 
        if (value == 0) {
          break; 
        }
        sum += value; 
      }
      mystack.push(sum);
    }
    else {
      int value = mystack.top();
      mystack.pop(); 
      value *= chemistry[i] - '0'; 
      mystack.push(value); 
    }
  }
  int res = 0;
  while (!mystack.empty()) {
    int value = mystack.top(); 
    mystack.pop();
    res += value; 
  }
  std::cout << res;
  return 0; 
}