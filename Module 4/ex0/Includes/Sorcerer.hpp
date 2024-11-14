#ifndef SORCERER_HPP
#define SORCERER_HPP
#include "Victim.hpp"
#include <iostream>

class Sorcerer {
public:
  Sorcerer() = delete;
  Sorcerer(const std::string &name, const std::string &title);
  ~Sorcerer();
  Sorcerer(const Sorcerer &copy);
  Sorcerer &operator=(const Sorcerer &Overload);
  std::string getName() const;
  std::string getTitle() const;
  void polymorph(const Victim &victim) const;

private:
  std::string _name;
  std::string _title;
};

std::ostream &operator<<(std::ostream &out, const Sorcerer &sorcerer);

#endif
