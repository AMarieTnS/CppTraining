#include "MiningBarge.hpp"

MiningBarge::MiningBarge() : iNunberLaser(0) { Laser.fill(nullptr); }

void MiningBarge::equip(IMiningLaser *laser) {
  if (iNunberLaser < 5) {
    Laser[iNunberLaser++] = laser;
  };
}

void MiningBarge::mine(IAsteroid *aste) const {
  for (int i = 0; i < iNunberLaser; ++i) {
    if (Laser[i]) {
      Laser[i]->mine(aste);
    }
  }
}
