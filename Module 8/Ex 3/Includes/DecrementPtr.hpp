#ifndef DECREMENTPTR_HPP
#define DECREMENTPTR_HPP
#include <memory>

class DecrementPtr
{
public:
    /* Constructors */
    DecrementPtr() = default;
    DecrementPtr(const DecrementPtr &other) = delete;
    ~DecrementPtr() = default;
    DecrementPtr(DecrementPtr &&other) = delete;
    DecrementPtr &operator=(const DecrementPtr &other) = delete;
    DecrementPtr &operator=(DecrementPtr &&other) = delete;

    /* Execution Functions */
    void operator()(char *&p);
};

#endif