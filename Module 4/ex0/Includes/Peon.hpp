#ifndef PEON_HPP
#define PEON_HPP
#include "Victim.hpp"

class Peon : public Victim {
public:
  Peon();
  Peon(const std::string &sName);
  ~Peon();
  Peon(const Peon &copy);
  Peon &operator=(const Peon &Overload);
  virtual void getPolymorphed() const;
};

#endif