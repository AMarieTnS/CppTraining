#include "../includes/Logger.hpp"
#include <chrono>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

void Logger::logToConsole(std::string const &sLogMessageConsole) {
  std::cout << sLogMessageConsole << std::endl << std::endl;
}

void Logger::logToFile(std::string const &sLogMessageFile) {
  std::fstream MyFile("LogFile.txt",
                      std::ios::in | std::ios::out | std::ios::app);
  if (!MyFile) {
    std::cerr << "Error: Could not open file " << "LogFile.txt" << std::endl;
    return;
  }
  MyFile << sLogMessageFile << std::endl;
  MyFile.seekg(0, std::ios::beg);

  std::string sContent((std::istreambuf_iterator<char>(MyFile)),
                       std::istreambuf_iterator<char>());
  std::cout << "Content after writing logs in file: " << std::endl
            << sContent << std::endl;
}

std::string Logger::makeLogEntry(std::string const &sLogMessageEntry) {
  auto now = std::chrono::system_clock::now();
  auto in_time_t = std::chrono::system_clock::to_time_t(now);
  std::tm buf;
  localtime_s(&buf, &in_time_t);
  std::ostringstream oss;
  oss << std::put_time(&buf, "%Y-%m-%d %H:%M:%S");
  return oss.str() + ": " + sLogMessageEntry;
}

void Logger::log(std::string const &dest, std::string const &message) {
  std::string sReelLogMessage = makeLogEntry(message);
  typedef void (Logger::*Fonction)(std::string const &target);
  Fonction actions[] = {&Logger::logToConsole, &Logger::logToFile};
  std::string sActionName[] = {"Console", "File"};
  for (int i = 0; i < 2; i++) {
    if (sActionName[i] == dest) {
      (this->*(actions[i]))(sReelLogMessage);
      return;
    }
  }
  std::cerr << "Unknown action: " << message << std::endl << std::endl;
}