#ifndef INTERN_HPP
#define INTERN_HPP

#include "Exceptions.hpp"
#include "Form.hpp"
#include <iostream>
#include <map>
#include <string>

class Intern {
public:
  Intern() = default;
  ~Intern() = default;

  Form *makeForm(const std::string &formName, const std::string &target);

private:
  typedef Form *(Intern::*FormCreator)(const std::string &target) const;
  Form *createShrubberyCreationForm(const std::string &target) const;
  Form *createRobotomyRequestForm(const std::string &target) const;
  Form *createPresidentialPardonForm(const std::string &target) const;
  Form *createMutantPigTerminationForm(const std::string &target) const;
};

#endif