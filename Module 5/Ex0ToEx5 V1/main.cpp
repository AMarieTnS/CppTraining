#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"
#include "OfficeBlock.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
  try { /*
     // Ex0
     Bureaucrat Pedro("Pedro", 50);
     Bureaucrat PedroBis("PedroBis", 50);
     Bureaucrat PedroPresident("PedroPresident", 5);

     Bureaucrat PedroLow("PedroLow", 150);
     Bureaucrat PedroHigh("PedroHigh", 1);

     std::cout << std::endl << "##Normal##" << std::endl;
     std::cout << Pedro << std::endl;
     Pedro.DecrementGrade();
     Pedro.IncrementGrade();

     std::cout << std::endl << "##Low##" << std::endl;
     std::cout << PedroLow << std::endl;
     try {
       PedroLow.DecrementGrade();
     } catch (const std::exception &e) {
       std::cerr << "Exception caught: " << e.what() << std::endl;
     }

     std::cout << std::endl << "##High##" << std::endl;
     std::cout << PedroHigh << std::endl;
     try {
       PedroHigh.IncrementGrade();
     } catch (const std::exception &e) {
       std::cerr << "Exception caught: " << e.what() << std::endl;
     }

     // Ex1
     std::cout << std::endl << "##Form##" << std::endl;
     try {
       ShrubberyCreationForm Major("Major");
       std::cout << Major << std::endl;
       Pedro.signForm(Major);
       std::cout << Major << std::endl;
     } catch (const std::exception &e) {
       std::cerr << "Exception caught: " << e.what() << std::endl;
     }

     try {
       ShrubberyCreationForm InvalidFormHigh("InvalidFormHigh");
     } catch (const std::exception &e) {
       std::cerr << "Exception caught: " << e.what() << std::endl;
     }

     try {
       ShrubberyCreationForm InvalidFormLow("InvalidFormLow");
     } catch (const std::exception &e) {
       std::cerr << "Exception caught: " << e.what() << std::endl;
     }

     try {
       ShrubberyCreationForm Amiral("Amiral");
       std::cout << Amiral << std::endl;
       PedroLow.signForm(Amiral);
       std::cout << Amiral << std::endl;
     } catch (const std::exception &e) {
       std::cerr << "Exception caught: " << e.what() << std::endl;
     }

     // Ex2
     std::cout << std::endl << "##Robot & Shrubbery##" << std::endl;

     ShrubberyCreationForm Shrubbery("Home");
     RobotomyRequestForm Robot("Garden");
     PresidentialPardonForm President("Bulding");

     Pedro.signForm(Shrubbery);
     Pedro.executeForm(Shrubbery);
     PedroBis.signForm(Robot);
     PedroBis.executeForm(Robot);
     PedroPresident.signForm(President);
     PedroPresident.executeForm(President);

     // Ex3
     std::cout << std::endl << "##Intern##" << std::endl;

     Intern someRandomIntern;
     Form *rrf;
     rrf = someRandomIntern.makeForm("robotomy request", "Bender");
     if (rrf) {
       Pedro.signForm(*rrf);
       Pedro.executeForm(*rrf);
       delete rrf;
     }*/

    // Ex4
    std::cout << std::endl << "##OfficeBlock##" << std::endl;
    Intern idiotOne;
    Bureaucrat hermes = Bureaucrat("Hermes Conrad", 37);
    Bureaucrat bob = Bureaucrat("Bobby Bobson", 123);
    OfficeBlock ob;
    ob.SetIntern(idiotOne);
    ob.SetSigner(bob);
    ob.SetExecutor(hermes);
    try {
      ob.doBureaucracy("mutant pig termination", "Pigley");
    } catch (OfficeBlock::SpecificException &e) {
      std::cerr << "Specific known error: " << e.what() << std::endl;

    } catch (std::exception &e) {
      std::cerr << "Unknown error: " << e.what() << std::endl;
    }

  } catch (const std::exception &e) {
    std::cerr << "Exception caught in main: " << e.what() << std::endl;
  }

  return 0;
}
