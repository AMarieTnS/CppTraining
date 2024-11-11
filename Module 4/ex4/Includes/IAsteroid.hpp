#ifndef IASTEROID_HPP
#define IASTEROID_HPP
#include "IMiningLaser.hpp"
#include <iostream>
#include <string>

class IAsteroid {
public:
  virtual ~IAsteroid() {}
  virtual std::string beMined(class StripMiner *) const = 0;
  virtual std::string beMined(class DeepCoreMiner *) const = 0;

  virtual std::string getName() const = 0;
};

#endif