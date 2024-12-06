#include "IncrementByte.hpp"

void IncrementByte::operator()(char *&p)
{
    ++(*p);
}