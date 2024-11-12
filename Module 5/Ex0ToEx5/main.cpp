#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
  try {
    Bureaucrat Pedro("Pedro", 50);
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

    std::cout << std::endl << "##Form##" << std::endl;
    try {
      Form Major("Major", 50, 50);
      std::cout << Major << std::endl;
      Pedro.signForm(Major);
      std::cout << Major << std::endl;
    } catch (const std::exception &e) {
      std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try {
      Form InvalidFormHigh("InvalidFormHigh", 0, 50);
    } catch (const std::exception &e) {
      std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try {
      Form InvalidFormLow("InvalidFormLow", 151, 50);
    } catch (const std::exception &e) {
      std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try {
      Form Amiral("Amiral", 150, 50);
      std::cout << Amiral << std::endl;
      PedroLow.signForm(Amiral);
      std::cout << Amiral << std::endl;
    } catch (const std::exception &e) {
      std::cerr << "Exception caught: " << e.what() << std::endl;
    }

  } catch (const std::exception &e) {
    std::cerr << "Exception caught in main: " << e.what() << std::endl;
  }

  return 0;
}
