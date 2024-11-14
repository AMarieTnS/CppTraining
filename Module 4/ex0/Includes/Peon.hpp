#ifndef PEON_HPP
#define PEON_HPP
#include "Victim.hpp"

class Peon : public Victim {
public:
  Peon() = delete;
  Peon(const std::string &name);
  ~Peon();
  Peon(const Peon &copy);
  Peon &operator=(const Peon &overload);
  void getPolymorphed() const override;
};

#endif