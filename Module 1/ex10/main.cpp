#include "Includes/ReadFile.hpp"

int main() {
  READFILE Read;
  Read.ReadFile("FirstFile.txt");
  Read.ReadFile("SecondFile.txt");
  Read.ReadFile("OtherFile.txt");

  return 0;
}