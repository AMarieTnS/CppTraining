#include "FileReader.hpp"
#include <fstream>
#include <sstream>
#include <stdexcept>

std::string FileReader::ReadFile(const std::string &filePath)
{
    std::ifstream file(filePath);
    if (!file.is_open())
    {
        throw std::runtime_error("Error: Could not open file '" + filePath + "'");
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    file.close();

    return buffer.str();
}