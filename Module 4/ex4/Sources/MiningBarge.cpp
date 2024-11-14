#include "MiningBarge.hpp"

MiningBarge::MiningBarge() : _nunberLaser(0) { _laser.fill(nullptr); }

void MiningBarge::equip(IMiningLaser *laser) {
  if (_nunberLaser < 5) {
    _laser[_nunberLaser++] = laser;
  };
}

void MiningBarge::mine(IAsteroid *aste) const {
  for (int i = 0; i < _nunberLaser; ++i) {
    if (_laser[i]) {
      _laser[i]->mine(aste);
    }
  }
}