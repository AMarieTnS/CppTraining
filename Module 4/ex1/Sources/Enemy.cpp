#include "Enemy.hpp"
#include <iostream>

Enemy::Enemy(int iHp, std::string const &sType) : iHp(iHp), sType(sType) {}
Enemy::~Enemy() {}
std::string Enemy::getType() const { return sType; }
int Enemy::getHP() const { return iHp; }
void Enemy::takeDamage(int iDamage) {
  if (iDamage > 0) {
    iHp -= iDamage;
    if (iHp < 0) {
      iHp = 0;
      std::cout << "SPROTCH " << std::endl;
    }
  }
}