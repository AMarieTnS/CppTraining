#ifndef SORCERER_HPP
#define SORCERER_HPP
#include "Victim.hpp"
#include <iostream>

class Sorcerer {
public:
  Sorcerer();
  Sorcerer(const std::string &sName, const std::string &sTitle);
  ~Sorcerer();
  Sorcerer(const Sorcerer &copy);
  Sorcerer &operator=(const Sorcerer &Overload);
  std::string getName() const;
  std::string getTitle() const;
  void setName(std::string const sName);
  void setTitle(std::string const sTitle);
  void polymorph(Victim const &victim) const;

private:
  std::string sName;
  std::string sTitle;
};

std::ostream &operator<<(std::ostream &out, const Sorcerer &sorcerer);

#endif
