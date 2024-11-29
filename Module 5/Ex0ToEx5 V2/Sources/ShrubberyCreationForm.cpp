#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : Form("Shrubbery Creation", 145, 137, target) {}

void ShrubberyCreationForm::Execute(const Bureaucrat &executor) const
{
  CheckExecution(executor);
  std::ofstream ofs(Form::GetTarget() + "_shrubbery");
  if (ofs)
  {
    ofs << "ASCII trees" << std::endl;
    ofs.close();
  }
  else
  {
    std::cerr << "Error creating file." << std::endl;
  }
}