#include "Data.hpp"
#include "Serialization.hpp"
#include <iostream>
#include <memory>
#include <cstdlib>
#include <ctime>

int main() {
  std::srand(std::time(0));

  std::unique_ptr<char[]> raw = serialize();
  std::unique_ptr<Data> data = deserialize(raw.release());

  std::cout << "s1: " << data->s1 << std::endl;
  std::cout << "n: " << data->n << std::endl;
  std::cout << "s2: " << data->s2 << std::endl;

  return 0;
}