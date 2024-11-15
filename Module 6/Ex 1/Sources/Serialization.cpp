#include "Serialization.hpp"
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>

char randomChar() {
  const char alphanum[] =
      "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
  return alphanum[rand() % (sizeof(alphanum) - 1)];
}

void *serialize(void) {
  char *raw = new char[20];

  for (int i = 0; i < 8; ++i) {
    raw[i] = randomChar();
  }

  int random = rand();
  std::memcpy(raw + 8, &random, sizeof(int));

  for (int i = 0; i < 8; ++i) {
    raw[12 + i] = randomChar();
  }

  return static_cast<void *>(raw);
}

Data *deserialize(void *raw) {
  Data *data = new Data;

  char *rawData = static_cast<char *>(raw);

  data->s1 = std::string(rawData, 8);
  std::memcpy(&data->n, rawData + 8, sizeof(int));
  data->s2 = std::string(rawData + 12, 8);

  return data;
}