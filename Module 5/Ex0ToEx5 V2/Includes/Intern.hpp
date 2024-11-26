#ifndef INTERN_HPP
#define INTERN_HPP

#include <memory>
#include <string>
#include "Form.hpp"

enum class FormType
{
  SHRUBBERY_CREATION,
  ROBOTOMY_REQUEST,
  PRESIDENTIAL_PARDON,
  MUTANT_PIG_TERMINATION,
  UNKNOWN_FORM
};

class Intern
{
public:
  Intern() = default;
  Intern(const Intern &other) = delete;
  Intern(Intern &&other) = delete;
  Intern &operator=(const Intern &other) = delete;
  Intern &operator=(Intern &&other) = delete;
  virtual ~Intern() = default;

  std::unique_ptr<Form> MakeForm(FormType formType, const std::string &target);
  std::unique_ptr<Form> MakeForm(const std::string &formName, const std::string &target);

private:
  std::unique_ptr<Form> createShrubberyCreationForm(const std::string &target) const;
  std::unique_ptr<Form> createRobotomyRequestForm(const std::string &target) const;
  std::unique_ptr<Form> createPresidentialPardonForm(const std::string &target) const;
  std::unique_ptr<Form> createMutantPigTerminationForm(const std::string &target) const;
};

FormType stringToFormType(const std::string &formName);

#endif