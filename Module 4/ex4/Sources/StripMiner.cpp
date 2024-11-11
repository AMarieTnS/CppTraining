#include "StripMiner.hpp"

void StripMiner::mine(IAsteroid *Result) {
  std::cout << "* strip mining... got " << Result->beMined(this) << "! *"
            << std::endl;
}
