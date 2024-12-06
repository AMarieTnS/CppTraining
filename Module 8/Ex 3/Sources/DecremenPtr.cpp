#include "DecrementPtr.hpp"

void DecrementPtr::operator()(char *&p)
{
    --p;
}