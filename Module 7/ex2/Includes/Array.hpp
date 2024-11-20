#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>
#include <memory>

template <typename T>
class Array
{
private:
  std::unique_ptr<T[]> _data;
  unsigned int _size;

public:
  Array() : _data(nullptr), _size(0) {}

  Array(unsigned int n) : _data(std::make_unique<T[]>(n)), _size(n)
  {
    for (unsigned int i = 0; i < _size; ++i)
    {
      _data[i] = T();
    }
  }

  ~Array()
  {
  }

  Array(const Array &other) : _data(std::make_unique<T[]>(other._size)), _size(other._size)
  {
    for (unsigned int i = 0; i < _size; ++i)
    {
      _data[i] = other._data[i];
    }
  }

  Array &operator=(const Array &other)
  {
    if (this != &other)
    {
      _data = std::make_unique<T[]>(other._size);
      _size = other._size;
      for (unsigned int i = 0; i < _size; ++i)
      {
        _data[i] = other._data[i];
      }
    }
    return *this;
  }

  T &operator[](unsigned int index)
  {
    if (index >= _size)
    {
      throw std::out_of_range("Out of the limits");
    }
    return _data[index];
  }

  unsigned int size() const
  {
    return _size;
  }
};

#endif