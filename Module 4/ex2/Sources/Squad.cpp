#include "Squad.hpp"
#include <algorithm>

Squad::Squad() {}
Squad::~Squad() {
  for (size_t Index = 0; Index < NthUnit.size(); Index++) {
    delete NthUnit[Index];
  }
}

int Squad::getCount() const { return NthUnit.size(); }

ISpaceMarine *Squad::getUnit(int index) const {
  ISpaceMarine *NumberCount = NthUnit[index];
  if (index < 0 || index >= static_cast<int>(NthUnit.size())) {
    NumberCount = nullptr;
  }
  return NumberCount;
}

int Squad::push(ISpaceMarine *marine) {
  if (marine) {
    for (size_t i = 0; i < NthUnit.size(); ++i) {
      if (NthUnit[i] == marine) {
        return NthUnit.size();
      }
    }
    NthUnit.push_back(marine);
  }
  return NthUnit.size();
}
