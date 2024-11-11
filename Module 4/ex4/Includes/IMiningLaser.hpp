#ifndef IMININGLASER_HPP
#define IMININGLASER_HPP
#include "IAsteroid.hpp"
#include <iostream>
class IAsteroid;

class IMiningLaser {
public:
  virtual ~IMiningLaser() {}
  virtual void mine(IAsteroid *) = 0;
};

#endif