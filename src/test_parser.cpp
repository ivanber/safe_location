#include "test_parser.h"
#include <sstream>
#include <string>
//------------------------------------------------------------------------------
bool NumParser::parse(std::istream &aStream, int &aNum) {
  bool success = false;

  std::string line;
  if ( std::getline(aStream, line) ) {
    std::istringstream iss(line);
    iss.exceptions(std::ios::failbit);

    try {
      iss >> aNum;

      success = true;
    } catch(std::exception const &exc) {
      std::cerr << "Fault parse num '" << line << "' "
        << exc.what() << std::endl;
    }
  }

  return success;
}
//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
bool PointParser::parse(std::istream &aStream, Point &aPoint) {
  bool success = false;

  std::string line;
  if ( std::getline(aStream, line) ) {
    try {
      int x = 0;
      int y = 0;
      int z = 0;

      std::istringstream iss(line);
      iss.exceptions(std::ios_base::failbit);
      iss >> x;
      iss >> y;
      iss >> z;

      aPoint.setX(x);
      aPoint.setY(y);
      aPoint.setZ(z);

      success = true;
    } catch(std::exception const &exc) {
      std::cerr << "Fault parse point '" << line << "' "
        << exc.what() << std::endl;
    }
  }

  return success;
}
//------------------------------------------------------------------------------
