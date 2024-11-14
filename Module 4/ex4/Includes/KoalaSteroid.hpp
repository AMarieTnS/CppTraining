#ifndef KoalaSteroid_HPP
#define KoalaSteroid_HPP
#include "IAsteroid.hpp"
#include <iostream>

class KoalaSteroid : public IAsteroid {
private:
public:
  std::string getName() const override;
  std::string beMined(class StripMiner *) const override;
  std::string beMined(class DeepCoreMiner *) const override;
};

#endif