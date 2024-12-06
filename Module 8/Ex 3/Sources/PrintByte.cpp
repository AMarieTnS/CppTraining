#include "PrintByte.hpp"

void PrintByte::operator()(char *&p)
{
    std::cout << *p;
}