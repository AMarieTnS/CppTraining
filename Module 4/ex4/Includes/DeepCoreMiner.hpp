#ifndef DEEPCOREMINER_HPP
#define DEEPCOREMINER_HPP
#include "IMiningLaser.hpp"
#include <iostream>
#include <string>

class DeepCoreMiner : public IMiningLaser {
public:
  void mine(IAsteroid *result) override;
};

#endif