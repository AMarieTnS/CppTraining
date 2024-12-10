#ifndef GENERATE_HPP
#define GENERATE_HPP

#include "classA.hpp"
#include "classB.hpp"
#include "classC.hpp"
#include <memory>
#include <variant>

using VariantBase = std::variant<std::monostate, ClassA, ClassB, ClassC>;

std::unique_ptr<VariantBase> generate();

#endif