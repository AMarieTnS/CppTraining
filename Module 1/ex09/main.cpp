#include "./Includes/Logger.hpp"

int main() {
  Logger logger;
  logger.log("Console", "Console Test");
  logger.log("File", "File Test");
  logger.log("Fax", "ERROR CASE : FAX");

  return 0;
}