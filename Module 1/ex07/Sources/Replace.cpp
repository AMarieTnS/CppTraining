#include "../includes/Replace.hpp"
#include <fstream>
#include <iostream>

void FILENAME::Replace(std::string &sFileName, std::string &s1, std::string &s2) {
    std::fstream MyFile(sFileName, std::ios::in | std::ios::out | std::ios::trunc);
    if (!MyFile) {
        std::cerr << "Error: Could not open file " << sFileName << std::endl;
        return;
    }

    MyFile << s1;
    MyFile.seekg(0, std::ios::beg);

    std::string content((std::istreambuf_iterator<char>(MyFile)), std::istreambuf_iterator<char>());
    std::cout << "Content after writing s1: " << content << std::endl;

    MyFile.seekp(0, std::ios::beg);

    MyFile << s2;
    MyFile.seekg(0, std::ios::beg);

    content.assign((std::istreambuf_iterator<char>(MyFile)), std::istreambuf_iterator<char>());
    std::cout << "Content after writing s2: " << content << std::endl;

    MyFile.close();
}