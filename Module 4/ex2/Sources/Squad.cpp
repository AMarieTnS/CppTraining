#include "Squad.hpp"
#include <algorithm>

Squad::~Squad() {
  for (size_t Index = 0; Index < _nthUnit.size(); Index++) {
    delete _nthUnit[Index];
  }
}

int Squad::getCount() const { return _nthUnit.size(); }

ISpaceMarine *Squad::getUnit(int index) const {
  ISpaceMarine *NumberCount = _nthUnit[index];
  if (index < 0 || index >= static_cast<int>(_nthUnit.size())) {
    NumberCount = nullptr;
  }
  return NumberCount;
}

int Squad::push(ISpaceMarine *marine) {
  if (marine) {
    for (size_t i = 0; i < _nthUnit.size(); ++i) {
      if (_nthUnit[i] == marine) {
        return _nthUnit.size();
      }
    }
    _nthUnit.push_back(marine);
  }
  return _nthUnit.size();
}
