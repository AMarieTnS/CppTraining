#include "Span.hpp"

int main()
{
  Span sp = Span(5);
  sp.AddNumber(5);
  sp.AddNumber(3);
  sp.AddNumber(17);
  sp.AddNumber(9);
  sp.AddNumber(11);
  std::cout << sp.ShortestSpan() << std::endl;
  std::cout << sp.LongestSpan() << std::endl;
}
