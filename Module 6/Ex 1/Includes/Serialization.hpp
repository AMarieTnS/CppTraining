#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include "Data.hpp"
#include <memory>

std::unique_ptr<char[]> serialize();
std::unique_ptr<Data> deserialize(void *raw);

#endif