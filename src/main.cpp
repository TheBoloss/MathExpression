#include <iostream>
#include <string>
#include <vector>
#include "Token.hpp"
#include "Lexer.hpp"

int main(int argc, char **argv)
{
  if (argc != 2)
  {
    std::cerr << "         -- MathExpression --\n"
              << "-- Calculate mathematic expressions --\n"
              << "Fatal: You must specify a math expression.\n\n"
              << "  Usage:   " << argv[0] << " <MathExpression>\n"
              << "  Example: " << argv[0] << " '3*2+4*9'" << std::endl;
    return 1;
  }
  std::string rawExpr = argv[1];

  Lexer lexer(rawExpr);
  Error tError = lexer.startCompute();
  if (tError.type())
  {
    std::string errorMsg;
    switch (tError.type())
    {
    case ErrorType::InvalidOperator:
      errorMsg = "Invalid operator";
      break;
    case ErrorType::InvalidStructure:
      errorMsg = "Invalid expression structure";
      break;
    default:
      errorMsg = "Unknown error";
      break;
    }
    std::cerr << "Fatal: " << errorMsg << " (position ";
    if (tError.position())
      std::cerr << tError.position();
    else
      std::cerr << "[unknown]";
    std::cerr << ")." << std::endl;
    return 1;
  }

  return 0;
}
