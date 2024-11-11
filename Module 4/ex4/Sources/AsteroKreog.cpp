#include "AsteroKreog.hpp"

std::string AsteroKreog::getName() const { return "AsteroKreog"; }

std::string AsteroKreog::beMined(StripMiner *) const { return "Flavium"; }

std::string AsteroKreog::beMined(DeepCoreMiner *) const { return "Dragonite"; }
