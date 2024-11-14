#ifndef SQUAD_HPP
#define SQUAD_HPP
#include "ISpaceMarine.hpp"
#include "ISquad.hpp"
#include <vector>

class Squad : public ISquad {
private:
  std::vector<ISpaceMarine *> _nthUnit;

public:
  Squad() = default;
  ~Squad();

  int getCount() const override;
  ISpaceMarine *getUnit(int) const override;
  int push(ISpaceMarine *nthUnit) override;
};

#endif
