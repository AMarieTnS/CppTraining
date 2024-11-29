#include "GenericForm.hpp"
#include <iostream>

GenericForm::GenericForm(const std::string &name, int gradeSign, int gradeExecute, const std::string &target)
    : Form(name, gradeSign, gradeExecute, target) {}

void GenericForm::Execute(const Bureaucrat &executor) const
{
    CheckExecution(executor);
    std::cout << "Bureaucrat " << executor.GetName() << " (Grade " << executor.GetGrade() << ") executes a "
              << GetName() << " Form (s.grade " << GetGradeSign() << ", ex.grade " << GetGradeExecute() << ") targeted on "
              << GetTarget() << " (Signed)" << std::endl;
    std::cout << "That'll do, " << GetTarget() << ". That'll do..." << std::endl;
}