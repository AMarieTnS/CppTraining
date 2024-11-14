#ifndef TACTICALMARINE_HPP
#define TACTICALMARINE_HPP
#include "ISpaceMarine.hpp"
#include <iostream>

class TacticalMarine : public ISpaceMarine {
public:
  TacticalMarine();
  ~TacticalMarine();

  ISpaceMarine *clone() const override;
  void battleCry() const override;
  void rangedAttack() const override;
  void meleeAttack() const override;
};

#endif