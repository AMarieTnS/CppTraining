
#include "./Includes/Replace.hpp"
#include <string>

int main()
{
    FILENAME FILENAME;
    std::string sFileName = "File.txt";
    std::string s1 = "Awasome text from s1";
    std::string s2 = "Awasome text from s2";

    FILENAME.Replace(sFileName, s1, s2);
    return 0;
}