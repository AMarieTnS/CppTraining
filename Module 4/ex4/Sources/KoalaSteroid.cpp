#include "KoalaSteroid.hpp"

std::string KoalaSteroid::getName() const { return "KoalaSteroid"; }

std::string KoalaSteroid::beMined(StripMiner *) const { return "Tartarite"; }

std::string KoalaSteroid::beMined(DeepCoreMiner *) const { return "Meium"; }
