#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template <typename T>
class Array
{
private:
  T *_data;
  unsigned int _size;

public:
  Array() : _data(nullptr), _size(0) {}

  Array(unsigned int n) : _data(new T[n]), _size(n)
  {
    for (unsigned int i = 0; i < _size; ++i)
    {
      _data[i] = T();
    }
  }

  ~Array()
  {
    delete[] _data;
  }

  Array(const Array &other) : _data(new T[other._size]), _size(other._size)
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
      delete[] _data;
      _data = new T[other._size];
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