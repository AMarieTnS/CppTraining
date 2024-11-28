#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include "Data.hpp"
#include <vector>
#include <string_view>
#include <memory>

std::vector<char> serialize();
std::unique_ptr<Data> deserialize(std::string_view buffer);

#endif