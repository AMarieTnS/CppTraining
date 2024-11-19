#include "Array.hpp"
#include <iostream>
#include <string>

int main()
{
  std::cout << "Integer Array: ";
  Array<int> intArray(5);
  for (unsigned int i = 0; i < intArray.size(); ++i)
  {
    intArray[i] = i * 2;
    std::cout << intArray[i] << " ";
  }

  std::cout << std::endl
            << "Double Array: ";
  Array<double> doubleArray(3);
  for (unsigned int i = 0; i < doubleArray.size(); ++i)
  {
    doubleArray[i] = i * 1.5;
    std::cout << doubleArray[i] << " ";
  }

  std::cout << std::endl
            << "String Array: ";
  Array<std::string> stringArray(3);
  stringArray[0] = "Hello";
  stringArray[1] = "world";
  stringArray[2] = "!";
  for (unsigned int i = 0; i < stringArray.size(); ++i)
  {
    std::cout << stringArray[i] << " ";
  }

  Array<int> copiedIntArray = intArray;
  Array<int> assignedIntArray(2);
  assignedIntArray = intArray;

  return 0;
}