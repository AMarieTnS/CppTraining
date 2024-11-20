#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "memory"

std::unique_ptr<Form> Intern::makeForm(const std::string &formName, const std::string &target)
{
  std::map<std::string, FormCreator> formCreators = {
      {"shrubbery creation", &Intern::createShrubberyCreationForm},
      {"robotomy request", &Intern::createRobotomyRequestForm},
      {"presidential pardon", &Intern::createPresidentialPardonForm},
      {"mutant pig termination", &Intern::createMutantPigTerminationForm}};

  auto it = formCreators.find(formName);
  if (it != formCreators.end()) {
    std::unique_ptr<Form> form = (this->*(it->second))(target);
    std::cout << "Intern creates a " << form->getName() << " Form (s.grade "
              << form->getGradeSign() << ", ex.grade "
              << form->getGradeExecute() << ") targeted on " << target
              << " (Unsigned)" << std::endl;
    return form;
  } else {
    throw UnknownFormException();
  }
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
  class MutantPigTerminationForm : public Form {
  public:
    MutantPigTerminationForm(const std::string &target)
        : Form("Mutant Pig Termination", 130, 50), _target(target) {}
    void execute(const Bureaucrat &executor) const override {
      if (!isSigned()) {
        throw GradeTooLowException();
      }
      if (executor.getGrade() > getGradeExecute()) {
        throw GradeTooHighException();
      }
      std::cout << "Bureaucrat " << executor.getName() << " (Grade "
                << executor.getGrade() << ") executes a " << getName()
                << " Form (s.grade " << getGradeSign() << ", ex.grade "
                << getGradeExecute() << ") targeted on " << _target
                << " (Signed)" << std::endl;
      std::cout << "That'll do, " << _target << ". That'll do..." << std::endl;
    }
    const std::string &getTarget() const override { return _target; }

  private:
    std::string _target;
  };

  return std::make_unique<MutantPigTerminationForm>(target);
}