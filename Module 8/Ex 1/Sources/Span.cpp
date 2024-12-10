#include "span.hpp"
#include <limits>
#include <algorithm>

Span::Span(unsigned int value) : _nElements(value) {}

void Span::AddNumber(int number)
{
    if (_fullNumbers.size() >= _nElements)
    {
        throw MaxSizeException();
    }
    _fullNumbers.push_back(number);
}

int Span::ShortestSpan() const
{
    if (_fullNumbers.size() < 2)
    {
        throw NotEnoughElementsException();
    }
    std::vector<int> sortedNumbers = _fullNumbers;
    std::sort(sortedNumbers.begin(), sortedNumbers.end());
    int shortest = std::numeric_limits<int>::max();
    for (size_t i = 1; i < sortedNumbers.size(); ++i)
    {
        int span = sortedNumbers[i] - sortedNumbers[i - 1];
        shortest = std::min(shortest, span);
    }
    return shortest;
}

int Span::LongestSpan() const
{
    if (_fullNumbers.size() < 2)
    {
        throw NotEnoughElementsException();
    }
    int min = *std::min_element(_fullNumbers.begin(), _fullNumbers.end());
    int max = *std::max_element(_fullNumbers.begin(), _fullNumbers.end());
    return max - min;
}