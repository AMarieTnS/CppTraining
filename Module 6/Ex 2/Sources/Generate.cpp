#include "generate.hpp"
#include <cstdlib>

std::unique_ptr<VariantBase> generate()
{
    int randomInstanciates = rand() % 4;
    switch (randomInstanciates)
    {
    case 0:
        return std::make_unique<VariantBase>(std::monostate{});
    case 1:
        return std::make_unique<VariantBase>(ClassA());
    case 2:
        return std::make_unique<VariantBase>(ClassB());
    case 3:
        return std::make_unique<VariantBase>(ClassC());
    default:
        return nullptr;
    }
}