#ifndef MININGBARGE_HPP
#define MININGBARGE_HPP
#include "IAsteroid.hpp"
#include "IMiningLaser.hpp"
#include <array>

class MiningBarge {
public:
  MiningBarge();
  void equip(IMiningLaser *);
  void mine(IAsteroid *) const;

private:
  std::array<IMiningLaser *, 4> _laser;
  int _nunberLaser;
};

#endif
