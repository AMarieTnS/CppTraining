#include <iostream>

template <typename T>
void swap(T &value1, T &value2);
template <typename T>
T min(const T &min1, const T &min2);
template <typename T>
T max(const T &max1, const T &max2);

template <typename T>
void swap(T &value1, T &value2)
{
  T tempVal1 = value1;
  value1 = value2;
  value2 = tempVal1;
}

template <typename T>
T min(const T &min1, const T &min2)
{
  T reelMin = min2;
  if (min1 < min2)
    reelMin = min1;
  return T(reelMin);
}

template <typename T>
T max(const T &max1, const T &max2)
{
  T reelMax = max2;
  if (max1 > max2)
    reelMax = max1;
  return T(reelMax);
}