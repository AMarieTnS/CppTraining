#ifndef VICTIM_HPP
#define VICTIM_HPP
#include <iostream>

class Victim {
public:
  Victim();
  Victim(const std::string &sName);
  ~Victim();
  Victim(const Victim &copy);
  Victim &operator=(const Victim &Overload);
  std::string getName() const;
  virtual void getPolymorphed() const;

private:
  std::string sName;
};
std::ostream &operator<<(std::ostream &out, const Victim &victim);

#endif