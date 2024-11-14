#include "Enemy.hpp"
#include <iostream>

Enemy::Enemy(int hp, const std::string &type) : _hp(hp), _type(type) {}
std::string Enemy::getType() const { return _type; }
int Enemy::getHP() const { return _hp; }
void Enemy::takeDamage(int damage) {
  if (damage > 0) {
    _hp -= damage;
    if (_hp <= 0) {
      _hp = 0;
      std::cout << "SPROTCH " << std::endl;
      delete this;
    }
  }
}