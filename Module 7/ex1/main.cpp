#include <iostream>

template <typename T> void iter(T *array, size_t length, void (*func)(T &)) {
  for (size_t i = 0; i < length; ++i) {
    func(array[i]);
  }
}

template <typename T> void print(T &element) { std::cout << element << " "; }

int main() {
  int intArray[] = {1, 2, 3, 4, 5};
  double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
  std::string stringArray[] = {"One", "Two", "three", "four", "five"};

  size_t intLength = sizeof(intArray) / sizeof(intArray[0]);
  std::cout << "integer array: ";
  iter(intArray, intLength, print);

  size_t doubleLength = sizeof(doubleArray) / sizeof(doubleArray[0]);
  std::cout << std::endl << "double array: ";
  iter(doubleArray, doubleLength, print);

  size_t stringLength = sizeof(stringArray) / sizeof(stringArray[0]);
  std::cout << std::endl << "string array: ";
  iter(stringArray, stringLength, print);

  return 0;
}
