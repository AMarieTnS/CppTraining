#include "Bureaucrat.hpp"

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
    // PedroLow.DecrementGrade();

    std::cout << std::endl << "##High##" << std::endl;
    std::cout << PedroHigh << std::endl;
    // PedroHigh.IncrementGrade();
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}