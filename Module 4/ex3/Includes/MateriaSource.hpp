#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
private:
  AMateria *templates[4];

public:
  MateriaSource();
  virtual ~MateriaSource();

  void learnMateria(AMateria *m) override;
  AMateria *createMateria(std::string const &type) override;
};

#endif
