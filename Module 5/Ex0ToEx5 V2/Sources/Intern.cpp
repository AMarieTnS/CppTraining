#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "MutantPigTerminationForm.hpp"
#include <memory>
#include <map>
#include <iostream>

FormType stringToFormType(const std::string &formName)
{
  if (formName == "shrubbery creation")
    return FormType::SHRUBBERY_CREATION;
  if (formName == "robotomy request")
    return FormType::ROBOTOMY_REQUEST;
  if (formName == "presidential pardon")
    return FormType::PRESIDENTIAL_PARDON;
  if (formName == "mutant pig termination")
    return FormType::MUTANT_PIG_TERMINATION;
  return FormType::UNKNOWN_FORM;
}

std::unique_ptr<Form> Intern::MakeForm(FormType formType, const std::string &target)
{
  std::unique_ptr<Form> form;
  switch (formType)
  {
  case FormType::SHRUBBERY_CREATION:
    form = createShrubberyCreationForm(target);
    break;
  case FormType::ROBOTOMY_REQUEST:
    form = createRobotomyRequestForm(target);
    break;
  case FormType::PRESIDENTIAL_PARDON:
    form = createPresidentialPardonForm(target);
    break;
  case FormType::MUTANT_PIG_TERMINATION:
    form = createMutantPigTerminationForm(target);
    break;
  default:
    throw std::runtime_error("Unknown form type");
  }
  std::cout << "Intern creates a " << form->GetName() << " Form (s.grade " << form->GetGradeSign() << ", ex.grade " << form->GetGradeExecute() << ") targeted on " << target << " (Unsigned)" << std::endl;
  return form;
}

std::unique_ptr<Form> Intern::MakeForm(const std::string &formName, const std::string &target)
{
  FormType formType = stringToFormType(formName);
  return MakeForm(formType, target);
}

std::unique_ptr<Form> Intern::createShrubberyCreationForm(const std::string &target) const
{
  return std::make_unique<ShrubberyCreationForm>(target);
}

std::unique_ptr<Form> Intern::createRobotomyRequestForm(const std::string &target) const
{
  return std::make_unique<RobotomyRequestForm>(target);
}

std::unique_ptr<Form> Intern::createPresidentialPardonForm(const std::string &target) const
{
  return std::make_unique<PresidentialPardonForm>(target);
}

std::unique_ptr<Form> Intern::createMutantPigTerminationForm(const std::string &target) const
{
  return std::make_unique<MutantPigTerminationForm>(target);
}