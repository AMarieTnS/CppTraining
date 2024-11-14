#include "DeepCoreMiner.hpp"

void DeepCoreMiner::mine(IAsteroid *result) {
  std::cout << "* mining deep... got " << result->beMined(this) << "! *"
            << std::endl;
}
