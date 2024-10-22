#include "../includes/ReadFile.hpp"
#include <fstream>
#include <iostream>

void READFILE::ReadFile(std::string const &sFilePath) {
  std::fstream MyFile(sFilePath, std::ios::in);
  if (!MyFile) {
    std::cerr << "Error: Could not open file " << sFilePath << std::endl;
    return;
  }

  std::string sContent((std::istreambuf_iterator<char>(MyFile)),
                       std::istreambuf_iterator<char>());
  std::cout << "Content : " << sContent << std::endl;

  MyFile.close();
}
