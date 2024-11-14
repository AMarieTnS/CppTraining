#include "StripMiner.hpp"

void StripMiner::mine(IAsteroid *result) {
  std::cout << "* strip mining... got " << result->beMined(this) << "! *"
            << std::endl;
}
