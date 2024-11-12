#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &sTarget)
    : Form("ShrubberyCreationForm", 145, 137), sTarget(sTarget) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
  if (!isSigned()) {
    throw Form::GradeTooLowException();
  }
  if (executor.GetGrade() > GetGradeExecute()) {
    throw Form::GradeTooLowException();
  }
  std::ofstream ShrubberyFile(sTarget + "_shrubbery.txt");
  ShrubberyFile << "ASCII trees" << std::endl;
  ShrubberyFile.close();
}
