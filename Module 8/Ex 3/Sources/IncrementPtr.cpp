#include "IncrementPtr.hpp"

void IncrementPtr::operator()(char *&p)
{
    ++p;
}