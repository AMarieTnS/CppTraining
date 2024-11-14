#ifndef ASTEROKREOG_HPP
#define ASTEROKREOG_HPP
#include "IAsteroid.hpp"
#include <iostream>

class AsteroKreog : public IAsteroid {
public:
  std::string getName() const override;
  std::string beMined(class StripMiner *) const override;
  std::string beMined(class DeepCoreMiner *) const override;
};

#endif