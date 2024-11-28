#ifndef IDENTIFY_HPP
#define IDENTIFY_HPP

#include "generate.hpp"
#include <iostream>
#include <memory>

void identify_from_pointer(const std::unique_ptr<VariantBase> &p);
void identify_from_reference(const VariantBase &p);

#endif