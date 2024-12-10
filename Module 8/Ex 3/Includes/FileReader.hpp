#ifndef FILEREADER_HPP
#define FILEREADER_HPP

#include <string>

class FileReader
{
public:
    /* Constructors */
    FileReader() = default;
    FileReader(const FileReader &other) = delete;
    ~FileReader() = default;
    FileReader(FileReader &&other) = delete;
    FileReader &operator=(const FileReader &other) = delete;
    FileReader &operator=(FileReader &&other) = delete;

    /* Execution Functions */
    std::string ReadFile(const std::string &filePath);
};

#endif