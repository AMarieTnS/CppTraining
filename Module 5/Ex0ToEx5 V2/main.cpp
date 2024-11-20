#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"
#include "OfficeBlock.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
  try {
    // Ex0
    Bureaucrat Pedro("Pedro", 50);
    Bureaucrat PedroBis("PedroBis", 50);
    Bureaucrat PedroPresident("PedroPresident", 5);

    Bureaucrat PedroLow("PedroLow", 150);
    Bureaucrat PedroHigh("PedroHigh", 1);

    std::cout << std::endl << "##Normal##" << std::endl;
    std::cout << Pedro << std::endl;
    Pedro.decrementGrade();
    Pedro.incrementGrade();

    std::cout << std::endl << "##Low##" << std::endl;
    std::cout << PedroLow << std::endl;
    try {
      PedroLow.decrementGrade();
    } catch (const std::exception &e) {
      std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << std::endl << "##High##" << std::endl;
    std::cout << PedroHigh << std::endl;
    try {
      PedroHigh.incrementGrade();
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
    std::unique_ptr<Form> rrf;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    if (rrf) {
      Pedro.signForm(*rrf);
      Pedro.executeForm(*rrf);
    }

    // Ex4
    std::cout << std::endl << "##OfficeBlock##" << std::endl;
    std::unique_ptr<Intern> idiotOne = std::make_unique<Intern>();
    std::unique_ptr<Bureaucrat> hermes = std::make_unique<Bureaucrat>("Hermes Conrad", 37);
    std::unique_ptr<Bureaucrat> bob = std::make_unique<Bureaucrat>("Bobby Bobson", 123);
    OfficeBlock ob;
    ob.setIntern(std::move(idiotOne));
    ob.setSigner(std::move(bob));
    ob.setExecutor(std::move(hermes));
    try {
      ob.doBureaucracy("mutant pig termination", "Pigley");
    }
    catch (std::exception &e)
    {
      std::cerr << "Specific known error: " << e.what() << std::endl;
    }
  } catch (const std::exception &e) {
    std::cerr << "Exception caught in main: " << e.what() << std::endl;
  }

  return 0;
}
