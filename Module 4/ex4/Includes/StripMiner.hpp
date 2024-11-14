#ifndef STRIPMINER_HPP
#define STRIPMINER_HPP
#include "IAsteroid.hpp"
#include <iostream>

class StripMiner : public IMiningLaser {
public:
  void mine(IAsteroid *result) override;
};

#endif