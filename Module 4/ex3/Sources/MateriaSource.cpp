#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
  for (int i = 0; i < MAX_MATERIAS; ++i)
    _templates[i] = nullptr;
}

MateriaSource::~MateriaSource() {
  for (int i = 0; i < MAX_MATERIAS; ++i) {
    if (_templates[i] != nullptr)
      delete _templates[i];
  }
}

void MateriaSource::learnMateria(AMateria *m) {
  for (int i = 0; i < MAX_MATERIAS; ++i) {
    if (_templates[i] == nullptr) {
      _templates[i] = m->clone();
      break;
    }
  }
}

AMateria *MateriaSource::createMateria(std::string const &type) {
  for (int i = 0; i < MAX_MATERIAS; ++i) {
    if (_templates[i] && _templates[i]->getType() == type)
      return _templates[i]->clone();
  }
  return nullptr;
}