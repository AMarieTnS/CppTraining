#include "Data.hpp"
#include <vector>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <memory>

char randomChar() {
  const char alphanum[] =
      "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
  return alphanum[rand() % (sizeof(alphanum) - 1)];
}

std::vector<char> serialize()
{
  std::vector<char> raw(20);

  for (int i = 0; i < 8; ++i)
  {
    raw[i] = randomChar();
  }

  int n = rand();
  std::memcpy(raw.data() + 8, &n, sizeof(int));

  for (int i = 0; i < 8; ++i)
  {
    raw[12 + i] = randomChar();
  }

  return raw;
}

std::unique_ptr<Data> deserialize(std::string_view buffer)
{
  auto data = std::make_unique<Data>();
  data->s1 = std::string(buffer.data(), 8);
  data->n = *reinterpret_cast<const int *>(buffer.data() + 8);
  data->s2 = std::string(buffer.data() + 12, 8);

  return data;
}