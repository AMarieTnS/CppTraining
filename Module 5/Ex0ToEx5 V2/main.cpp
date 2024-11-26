#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"
#include "OfficeBlock.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "MutantPigTerminationForm.hpp"

int main() {
  try
  {
    Intern idiotOne;
    Bureaucrat hermes("Hermes Conrad", 37);
    Bureaucrat bob("Bobby Bobson", 123);
    OfficeBlock ob;
    ob.SetIntern(std::make_unique<Intern>());
    ob.SetSigner(std::make_unique<Bureaucrat>(bob));
    ob.SetExecutor(std::make_unique<Bureaucrat>(hermes));
    try
    {
      ob.DoBureaucracy(FormType::MUTANT_PIG_TERMINATION, "Pigley");
    }
    catch (const std::exception &e)
    {
      std::cerr << "Specific known error: " << e.what() << std::endl;
    }
  }
  catch (const std::exception &e)
  {
    std::cerr << "Exception caught in main: " << e.what() << std::endl;
  }

  return 0;
}