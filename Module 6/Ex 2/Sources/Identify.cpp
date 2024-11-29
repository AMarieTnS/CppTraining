#include "identify.hpp"

void identify_from_pointer(const std::unique_ptr<VariantBase> &p)
{
    if (!p)
    {
        std::cout << "ERROR POINTER" << std::endl;
        return;
    }

    const auto &variant = *p;
    if (std::holds_alternative<std::monostate>(variant))
        std::cout << "EMPTY" << std::endl;
    else if (std::holds_alternative<ClassA>(variant))
        std::cout << "A" << std::endl;
    else if (std::holds_alternative<ClassB>(variant))
        std::cout << "B" << std::endl;
    else if (std::holds_alternative<ClassC>(variant))
        std::cout << "C" << std::endl;
    else
        std::cout << "ERROR" << std::endl;
}

void identify_from_reference(const VariantBase &p)
{
    if (std::holds_alternative<std::monostate>(p))
        std::cout << "EMPTY" << std::endl;
    else if (std::holds_alternative<ClassA>(p))
        std::cout << "A" << std::endl;
    else if (std::holds_alternative<ClassB>(p))
        std::cout << "B" << std::endl;
    else if (std::holds_alternative<ClassC>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "ERROR" << std::endl;
}