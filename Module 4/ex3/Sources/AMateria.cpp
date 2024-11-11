#include "AMateria.hpp"

AMateria::AMateria(std::string const &type) : sTypes(type), _xp(0) {}

AMateria::~AMateria() {}

std::string const &AMateria::getType() const { return sTypes; }

unsigned int AMateria::getXP() const { return _xp; }

void AMateria::use(ICharacter &target) {
  (void)target;
  _xp += 10;
}
