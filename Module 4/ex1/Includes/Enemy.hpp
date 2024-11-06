#ifndef ENEMY_HPP
#define ENEMY_HPP
#include <iostream>

class Enemy {
private:
  int iHp;
  std::string sType;

public:
  Enemy(int iHp, std::string const &sType);
  virtual ~Enemy();
  std::string virtual getType() const;
  int getHP() const;
  virtual void takeDamage(int iDamage);
};
std::ostream &operator<<(std::ostream &out, const Enemy &Enemy);

#endif