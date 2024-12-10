#ifndef DECREMENTBYTE_HPP
#define DECREMENTBYTE_HPP
#include <memory>

class DecrementByte
{
public:
    /* Constructors */
    DecrementByte() = default;
    DecrementByte(const DecrementByte &other) = delete;
    ~DecrementByte() = default;
    DecrementByte(DecrementByte &&other) = delete;
    DecrementByte &operator=(const DecrementByte &other) = delete;
    DecrementByte &operator=(DecrementByte &&other) = delete;

    /* Execution Functions */
    void operator()(char *&p);
};

#endif