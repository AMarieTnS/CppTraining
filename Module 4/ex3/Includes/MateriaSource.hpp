#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP
#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
private:
  static constexpr int MAX_MATERIAS = 4;
  AMateria *_templates[MAX_MATERIAS];

public:
  MateriaSource();
  ~MateriaSource();

  void learnMateria(AMateria *m) override;
  AMateria *createMateria(std::string const &type) override;
};

#endif