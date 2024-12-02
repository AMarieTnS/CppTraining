#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <exception>
class Easyfind
{
public:
  /* Constructors */
  Easyfind() = default;
  Easyfind(const Easyfind &other) = delete;
  ~Easyfind() = default;
  Easyfind(Easyfind &&other) = delete;
  Easyfind &operator=(const Easyfind &other) = delete;
  Easyfind &operator=(Easyfind &&other) = delete;
};

class NotFoundException : public std::exception
{
public:
  const char *what() const noexcept override
  {
    return "Element not found";
  }
};

template <typename T>
typename T::iterator easyfind(T &container, int value)
{
  typename T::iterator it = std::find(container.begin(), container.end(), value);
  if (it == container.end())
  {
    throw NotFoundException();
  }
  return it;
}

#endif