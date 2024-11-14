#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : Form("ShrubberyCreationForm", 145, 137), _target(target) {}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
  if (!isSigned()) {
    throw Form::GradeTooLowException();
  }
  if (executor.getGrade() > getGradeExecute()) {
    throw Form::GradeTooLowException();
  }
  std::ofstream ShrubberyFile(_target + "_shrubbery.txt");
  ShrubberyFile << "ASCII trees" << std::endl;
  ShrubberyFile.close();
}
