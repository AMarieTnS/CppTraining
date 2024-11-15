#include "Data.hpp"
#include "Serialization.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main() {
  std::srand(std::time(0));

  void *raw = serialize();
  Data *data = deserialize(raw);

  std::cout << "s1: " << data->s1 << std::endl;
  std::cout << "n: " << data->n << std::endl;
  std::cout << "s2: " << data->s2 << std::endl;

  delete[] static_cast<char *>(raw);
  delete data;

  return 0;
}