#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <iterator>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
  /* Constructors */
  MutantStack() = default;
  MutantStack(const MutantStack &other) = delete;
  ~MutantStack() = default;
  MutantStack(MutantStack &&other) = delete;
  MutantStack &operator=(const MutantStack &other) = delete;
  MutantStack &operator=(MutantStack &&other) = delete;

  /* Execution Functions */
  using std::stack<T>::stack;
  using iterator = typename std::stack<T>::container_type::iterator;

  iterator begin() { return std::stack<T>::c.begin(); }
  iterator end() { return std::stack<T>::c.end(); }
};

#endif