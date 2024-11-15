#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include "Data.hpp"
#include <iostream>
#include <string>

void *serialize(void);
Data *deserialize(void *raw);

#endif