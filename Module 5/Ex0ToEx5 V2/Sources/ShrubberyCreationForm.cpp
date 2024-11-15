#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : Form("Shrubbery Creation", 145, 137), _target(target) {}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
  if (!isSigned()) {
    throw GradeException("Grade too low");
  }
  if (executor.getGrade() > getGradeExecute()) {
    throw GradeException("Grade too hight");
  }
  std::ofstream ofs(_target + "_shrubbery");
  if (ofs) {
    ofs << "ASCII trees" << std::endl;
    ofs.close();
  } else {
    std::cerr << "Error creating file." << std::endl;
  }
}

const std::string &ShrubberyCreationForm::getTarget() const { return _target; }