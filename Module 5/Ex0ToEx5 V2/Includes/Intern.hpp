#ifndef INTERN_HPP
#define INTERN_HPP

#include "Exceptions.hpp"
#include "Form.hpp"
#include <iostream>
#include <map>
#include <string>
#include "memory"

class Intern {
public:
  Intern() = default;
  ~Intern() = default;

  std::unique_ptr<Form> makeForm(const std::string &formName, const std::string &target);

private:
  typedef std::unique_ptr<Form> (Intern::*FormCreator)(const std::string &target) const;
  std::unique_ptr<Form> createShrubberyCreationForm(const std::string &target) const;
  std::unique_ptr<Form> createRobotomyRequestForm(const std::string &target) const;
  std::unique_ptr<Form> createPresidentialPardonForm(const std::string &target) const;
  std::unique_ptr<Form> createMutantPigTerminationForm(const std::string &target) const;
};
#endif