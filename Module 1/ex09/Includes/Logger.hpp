#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>

class Logger {
public:
  void log(std::string const & dest, std::string const & message);

private:
  void logToConsole(std::string const &sLogMessageConsole);
  void logToFile(std::string const &sLogMessageFile);
  std::string makeLogEntry(std::string const &sLogMessageEntry);
};
#endif
