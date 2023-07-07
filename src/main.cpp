#include <iostream>
#include <string>
#include <format>

int main(int argc, char **argv)
{
  if (argc != 2)
  {
    std::cerr << std::format("-- MathExpression --\nYou must specify a math expression.\n\n  Usage:   {} <MathExpression>\n  Example: {} '3*2+4*9'\n", argv[0], argv[0]);
    return 1;
  }
  std::string rawExpr = argv[1];
  std::cout << std::format(">>> Raw \"{}\" -> length: {}", rawExpr, rawExpr.length()) << std::endl;
  return 0;
}
