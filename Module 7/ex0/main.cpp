#include "Whatever"
#include <iostream>

int main() {
  int x = 10, y = 20;
  std::cout << "Before swap: x = " << x << ", y = " << y << std::endl;
  swap(x, y);
  std::cout << "After swap: x = " << x << ", y = " << y << std::endl;

  std::cout << "min(x, y) = " << min(x, y) << std::endl;
  std::cout << "max(x, y) = " << max(x, y) << std::endl;

  double a = 5.5, b = 2.2;
  std::cout << "min(a, b) = " << min(a, b) << std::endl;
  std::cout << "max(a, b) = " << max(a, b) << std::endl;

  return 0;
}
