#include "DecrementByte.hpp"

void DecrementByte::operator()(char *&p)
{
    --(*p);
}