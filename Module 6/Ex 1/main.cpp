#include <iostream>
#include "Data.hpp"
#include <vector>
#include "Serialization.hpp"
#include <ctime>

int main() {
  std::srand(std::time(0));
  std::vector<char> serializedData = serialize();
  std::unique_ptr<Data> data = deserialize(std::string_view(serializedData.data(), serializedData.size()));

  std::cout << "s1: " << data->s1 << std::endl;
  std::cout << "n: " << data->n << std::endl;
  std::cout << "s2: " << data->s2 << std::endl;

  return 0;
}