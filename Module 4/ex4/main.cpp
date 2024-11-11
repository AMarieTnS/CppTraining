#include "AsteroKreog.hpp"
#include "DeepCoreMiner.hpp"
#include "IAsteroid.hpp"
#include "IMiningLaser.hpp"
#include "KoalaSteroid.hpp"
#include "MiningBarge.hpp"
#include "StripMiner.hpp"

int main() {
  DeepCoreMiner Deep;
  KoalaSteroid Comet;
  AsteroKreog Astero;
  StripMiner Strip;
  MiningBarge Mining;

  Mining.equip(&Deep);
  Mining.equip(&Strip);
  Mining.mine(&Astero);
  Mining.mine(&Comet);

  return 0;
}