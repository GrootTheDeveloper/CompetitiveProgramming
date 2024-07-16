#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <string>
int main() {
  std::set <int> myset;
  while (true) {
    int type;
    std::cin >> type;
    if (type == 1) {
      int x;
      std::cin >> x;
      myset.insert(x);
    }
    else if (type == 2) {
      int x;
      std::cin >> x; 
      std::set <int>::iterator it = myset.find(x);
      if (it != myset.end()) {
        myset.erase(it);
      }
    }
    else if (type == 3) {
      if (myset.empty() == false) {
        std::cout << *myset.begin() << std::endl;
      }
      else {
        std::cout << "empty" << std::endl;
      }
    }
    else if (type == 4) {
      if (myset.empty() == false) {
        std::set <int>::iterator it = myset.end();
        it--;
        std::cout << *it << std::endl;
      }
      else {
        std::cout << "empty" << std::endl;
      }
    }
    else if (type == 5) {
      int x;
      std::cin >> x;
      if (myset.empty() == false) {
        std::set <int>::iterator it = myset.upper_bound(x);
        if (it != myset.end()) {
          std::cout << *it << std::endl;
        }
        else {
          std::cout << "no" << std::endl;
        }
      }
      else {
        std::cout << "empty" << std::endl;
      }
    }
    else if (type == 6) {
      int x;
      std::cin >> x;
      if (myset.empty() == false) {
        std::set <int>::iterator it = myset.lower_bound(x);
        if (it != myset.end()) {
          std::cout << *it << std::endl;
        }
        else {
          std::cout << "no" << std::endl;
        }
      }
      else {
        std::cout << "empty" << std::endl;
      }
    }
    else if (type == 7) {
      int x;
      std::cin >> x;
      if (myset.empty() == false) {
        std::set <int>::iterator it = myset.lower_bound(x);
        if (it != myset.begin()) {
          it--;
          std::cout << *it << std::endl;
        }
        else {
          std::cout << "no" << std::endl;
        }
      }
      else {
        std::cout << "empty" << std::endl;
      }
    }
    else if (type == 8) {
      int x;
      std::cin >> x;
      if (myset.empty() == false) {
        std::set <int>::iterator it = myset.upper_bound(x);
        if (it != myset.begin()) {
          it--;
          std::cout << *it << std::endl;
        }
        else {
          std::cout << "no" << std::endl;
        }
      }
      else {
        std::cout << "empty" << std::endl;
      }
    }
    else if (type == 0) {
      break;
    }
  }
  return 0;
}