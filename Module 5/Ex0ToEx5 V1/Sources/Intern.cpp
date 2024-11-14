#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

Form *Intern::makeForm(const std::string &nameForm,
                       const std::string &targetForm) {
  std::string formTypes[4] = {"shrubbery creation", "robotomy request",
                              "presidential pardon", "mutant pig termination"};
  Form *forms[4] = {new ShrubberyCreationForm(targetForm),
                    new RobotomyRequestForm(targetForm),
                    new PresidentialPardonForm(targetForm), nullptr};

  Form *form = nullptr;
  for (int i = 0; i < 4; ++i) {
    if (formTypes[i] == nameForm) {
      if (i == 3) {
        std::cout << "Intern creates a Mutant Pig Termination Form (s.grade "
                     "130, ex.grade 50) targeted on "
                  << targetForm << " (Unsigned)" << std::endl;
        return new ShrubberyCreationForm(targetForm);
      }
      std::cout << "Intern creates " << nameForm << std::endl;

      return forms[i];
    }
    delete forms[i];
  }
  std::cout << "Error: Form type " << nameForm << " not recognized."
            << std::endl;
  return form;
}