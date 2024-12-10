#ifndef INCREMENTBYTE_HPP
#define INCREMENTBYTE_HPP
#include <memory>

class IncrementByte
{
public:
    /* Constructors */
    IncrementByte() = default;
    IncrementByte(const IncrementByte &other) = delete;
    ~IncrementByte() = default;
    IncrementByte(IncrementByte &&other) = delete;
    IncrementByte &operator=(const IncrementByte &other) = delete;
    IncrementByte &operator=(IncrementByte &&other) = delete;

    /* Execution Functions */
    void operator()(char *&p);
};

#endif