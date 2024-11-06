#ifndef POWERFIST_HPP
#define POWERFIST_HPP
#include "AWeapon.hpp"

class PowerFist : public AWeapon {
public:
  PowerFist();
  virtual ~PowerFist();
  void attack() const;
};
#endif