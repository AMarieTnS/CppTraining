#include "DeepCoreMiner.hpp"

void DeepCoreMiner::mine(IAsteroid *Result) {
  std::cout << "* mining deep... got " << Result->beMined(this) << "! *"
            << std::endl;
}
