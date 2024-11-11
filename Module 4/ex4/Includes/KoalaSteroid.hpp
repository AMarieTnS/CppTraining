#ifndef KoalaSteroid_HPP
#define KoalaSteroid_HPP
#include "IAsteroid.hpp"
#include <iostream>

class KoalaSteroid : public IAsteroid {
private:
public:
  std::string getName() const;
  std::string beMined(class StripMiner *) const;
  std::string beMined(class DeepCoreMiner *) const;
};

#endif