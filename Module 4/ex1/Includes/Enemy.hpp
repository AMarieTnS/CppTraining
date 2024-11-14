#include <string>
#ifndef ENEMY_HPP
#define ENEMY_HPP
#define ENEMY_HPP

class Enemy {
private:
  int _hp;
  std::string _type;

public:
  Enemy(int hp, const std::string &type);
  virtual ~Enemy() = default;
  virtual std::string getType() const;
  int getHP() const;
  virtual void takeDamage(int damage);
};

std::ostream &operator<<(std::ostream &out, const Enemy &enemy);

#endif