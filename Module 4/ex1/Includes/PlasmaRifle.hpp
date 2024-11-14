#ifndef PLASMARIFLE_HPP
#define PLASMARIFLE_HPP
#include "AWeapon.hpp"

class PlasmaRifle : public AWeapon {
public:
  PlasmaRifle();
  virtual ~PlasmaRifle() = default;
  void attack() const override;
};
#endif