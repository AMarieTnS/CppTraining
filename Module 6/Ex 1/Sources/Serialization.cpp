#include "Serialization.hpp"
#include <iostream>
#include <cstring>
#include <cstdlib>

char randomChar() {
  const char alphanum[] =
      "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
  return alphanum[rand() % (sizeof(alphanum) - 1)];
}

std::unique_ptr<char[]> serialize()
{
  auto raw = std::make_unique<char[]>(20);

  for (int i = 0; i < 8; ++i) {
    raw[i] = randomChar();
  }

  int random = rand();
  std::memcpy(raw.get() + 8, &random, sizeof(int));

  for (int i = 0; i < 8; ++i) {
    raw[12 + i] = randomChar();
  }

  return std::unique_ptr<char[]>(raw.release());
}

std::unique_ptr<Data> deserialize(void *raw)
{
  auto data = std::make_unique<Data>();

  char *rawData = static_cast<char *>(raw);

  data->s1 = std::string(rawData, 8);
  std::memcpy(&data->n, rawData + 8, sizeof(int));
  data->s2 = std::string(rawData + 12, 8);

  return data;
}