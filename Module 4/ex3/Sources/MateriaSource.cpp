#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
  for (int i = 0; i < 4; ++i)
    templates[i] = nullptr;
}

MateriaSource::~MateriaSource() {
  for (int i = 0; i < 4; ++i) {
    if (templates[i])
      delete templates[i];
  }
}

void MateriaSource::learnMateria(AMateria *m) {
  for (int i = 0; i < 4; ++i) {
    if (!templates[i]) {
      templates[i] = m->clone();
      break;
    }
  }
}

AMateria *MateriaSource::createMateria(std::string const &sType) {
  for (int i = 0; i < 4; ++i) {
    if (templates[i] && templates[i]->getType() == sType)
      return templates[i]->clone();
  }
  return nullptr;
}
