#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <exception>
#include <vector>

class Span
{
public:
  /* Constructors */
  Span(unsigned int N);
  Span(const Span &other) = delete;
  ~Span() = default;
  Span(Span &&other) = delete;
  Span &operator=(const Span &other) = delete;
  Span &operator=(Span &&other) = delete;

  /* Execution Functions */
  void AddNumber(int number);
  int ShortestSpan() const;
  int LongestSpan() const;

private:
  std::vector<int> _fullNumbers;
  unsigned int _nElements;
};

class MaxSizeException : public std::exception
{
public:
  const char *what() const noexcept override
  {
    return "Cannot add more numbers, span is full.";
  }
};

class NotEnoughElementsException : public std::exception
{
public:
  const char *what() const noexcept override
  {
    return "Not enough elements to calculate span.";
  }
};

#endif