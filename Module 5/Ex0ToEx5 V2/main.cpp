#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"
#include "OfficeBlock.hpp"

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
      ob.DoBureaucracy("mutant pig termination", "Pigley");
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