#ifndef SQUAD_HPP
#define SQUAD_HPP
#include "ISpaceMarine.hpp"
#include "ISquad.hpp"
#include <vector>

class Squad : public ISquad {
private:
  std::vector<ISpaceMarine *> NthUnit;

public:
  Squad();
  ~Squad();

  int getCount() const;
  ISpaceMarine *getUnit(int) const;
  int push(ISpaceMarine *NthUnit);
};

#endif
