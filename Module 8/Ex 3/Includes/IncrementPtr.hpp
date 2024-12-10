#ifndef INCREMENTPTR_HPP
#define INCREMENTPTR_HPP
#include <memory>

class IncrementPtr
{
public:
    /* Constructors */
    IncrementPtr() = default;
    IncrementPtr(const IncrementPtr &other) = delete;
    ~IncrementPtr() = default;
    IncrementPtr(IncrementPtr &&other) = delete;
    IncrementPtr &operator=(const IncrementPtr &other) = delete;
    IncrementPtr &operator=(IncrementPtr &&other) = delete;

    /* Execution Functions */
    void operator()(char *&p);
};

#endif