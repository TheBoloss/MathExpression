#ifndef LEXER_HPP
#define LEXER_HPP

#include <string>
#include <vector>
#include "Error.hpp"
#include "types.hpp"
#include "Token.hpp"

class Lexer
{
private:
  std::string m_rawExpr;
  std::vector<std::string> m_splitExpr;
  std::vector<Token> m_tokenList;
  std::vector<std::string> splitString(const std::string &input);
  Operator::Operator getOperatorFromString(const std::string &input);
  bool isNumber(const std::string &input);
  unsigned int getPriorityOperator();
  Error calculate(unsigned int position);
  Error tokenizeExpression();

public:
  Lexer(std::string rawExpr);
  Error startCompute();
};

#endif