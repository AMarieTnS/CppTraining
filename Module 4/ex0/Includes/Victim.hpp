#ifndef VICTIM_HPP
#define VICTIM_HPP
#include <iostream>

class Victim {
public:
  Victim();
  Victim(const std::string &name);
  virtual ~Victim();
  Victim(const Victim &copy);
  Victim &operator=(const Victim &overload);
  std::string getName() const;
  virtual void getPolymorphed() const;

private:
  std::string _name;
};
std::ostream &operator<<(std::ostream &out, const Victim &victim);

#endif