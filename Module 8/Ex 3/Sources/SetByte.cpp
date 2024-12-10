#include "SetByte.hpp"

void SetByte::operator()(char *&p)
{
    std::cin >> *p;
}