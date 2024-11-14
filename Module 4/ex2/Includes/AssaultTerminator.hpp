#ifndef ASSAULTTERMINATOR_HPP
#define ASSAULTTERMINATOR_HPP
#include "ISpaceMarine.hpp"
#include <iostream>

class AssaultTerminator : public ISpaceMarine {
public:
  AssaultTerminator();
  ~AssaultTerminator();

  ISpaceMarine *clone() const override;
  void battleCry() const override;
  void rangedAttack() const override;
  void meleeAttack() const override;
};

#endif