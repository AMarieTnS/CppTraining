#include "MutantPigTerminationForm.hpp"
#include <iostream>

MutantPigTerminationForm::MutantPigTerminationForm(const std::string &target)
    : Form("Mutant Pig Termination", 130, 50, target) {}

void MutantPigTerminationForm::Execute(const Bureaucrat &executor) const
{
    if (!IsSigned())
    {
        throw GradeTooLowException();
    }
    if (executor.GetGrade() > GetGradeExecute())
    {
        throw GradeTooHighException();
    }
    std::cout << "Bureaucrat " << executor.GetName() << " (Grade " << executor.GetGrade() << ") executes a " << GetName() << " Form (s.grade " << GetGradeSign() << ", ex.grade " << GetGradeExecute() << ") targeted on " << Form::GetTarget() << " (Signed)" << std::endl;
    std::cout << "That'll do, " << Form::GetTarget() << ". That'll do..." << std::endl;
}