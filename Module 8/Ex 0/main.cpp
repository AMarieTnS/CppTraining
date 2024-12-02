#include "Easyfind.hpp"
#include <vector>
#include <list>

int main()
{
  try
  {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::list<int> lst = {10, 20, 30, 40, 50};

    std::cout << "Vector: " << *easyfind(vec, 3) << std::endl;

    std::cout << "List: " << *easyfind(lst, 20) << std::endl;
    std::cout << "Vector: " << *easyfind(vec, 6) << std::endl;
  }
  catch (const NotFoundException &e)
  {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}