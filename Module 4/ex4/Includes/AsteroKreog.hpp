#ifndef ASTEROKREOG_HPP
#define ASTEROKREOG_HPP
#include "IAsteroid.hpp"
#include <iostream>

class AsteroKreog : public IAsteroid {
public:
  std::string getName() const;
  std::string beMined(class StripMiner *) const;
  std::string beMined(class DeepCoreMiner *) const;
};

#endif