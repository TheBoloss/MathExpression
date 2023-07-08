#include "Lexer.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include "Error.hpp"
#include "types.hpp"

Lexer::Lexer(std::string rawExpr) : m_rawExpr(rawExpr), m_splitExpr(std::vector<std::string>{}) {}

Operator::Operator Lexer::getOperatorFromString(const std::string &input)
{
  Operator::Operator finalOp;

  if (input == "+")
    finalOp = Operator::Add;
  else if (input == "-")
    finalOp = Operator::Sub;
  else if (input == "*")
    finalOp = Operator::Mult;
  else if (input == "x")
    finalOp = Operator::Mult;
  else if (input == "/")
    finalOp = Operator::Div;
  else if (input == ":")
    finalOp = Operator::Div;
  else
    finalOp = Operator::Error;

  return finalOp;
}

bool Lexer::isNumber(const std::string &input)
{
  bool hasDecimal = false;
  bool hasDigit = false;

  for (char c : input)
  {
    if (std::isdigit(c))
    {
      hasDigit = true;
    }
    else if (c == '.')
    {
      if (hasDecimal)
      {
        // Multiple decimal points are not allowed
        return false;
      }
      hasDecimal = true;
    }
    else
    {
      // Invalid character found
      return false;
    }
  }

  // At least one digit must be present
  return hasDigit;
}

unsigned int Lexer::getPriorityOperator()
{
  std::map<Operator::Operator, unsigned int> priorities;
  priorities[Operator::Add] = 1;
  priorities[Operator::Sub] = 1;
  priorities[Operator::Mult] = 2;
  priorities[Operator::Div] = 2;
  unsigned int i = 0;
  unsigned int higherPriority = 0;
  unsigned int higherPriorityPosition = 0;

  for (const auto &token : m_tokenList)
  {
    if (token.type() == TokenType::OperatorT)
    {
      if (priorities[token.getOperator()] > higherPriority)
      {
        higherPriority = priorities[token.getOperator()];
        higherPriorityPosition = i;
      }
    }
    i++;
  }
  return higherPriorityPosition;
}

Error Lexer::calculate(unsigned int position)
{
  Error error;
  if (m_tokenList[position].type() == NumericConstantT)
  {
    error.setType(ErrorType::InvalidStructure);
    return error;
  }

  // If position is not between 1 and
  // m_tokenList.size() - 2 included,
  // then error (operator cannot be the
  // first or the last token)
  if (!(position > 0 && position < (m_tokenList.size() - 1)))
  {
    error.setType(ErrorType::InvalidStructure);
    return error;
  }

  // If operator is not surrounded by numbers,
  // then error
  if (m_tokenList[position - 1].type() == TokenType::OperatorT || m_tokenList[position + 1].type() == TokenType::OperatorT)
  {
    error.setType(ErrorType::InvalidStructure);
    return error;
  }

  auto operatorToken = m_tokenList[position];
  float result = 0;
  const float beforeValue = m_tokenList[position - 1].value();
  const float afterValue = m_tokenList[position + 1].value();
  switch (operatorToken.getOperator())
  {
  case Operator::Add:
    result = beforeValue + afterValue;
    break;
  case Operator::Sub:
    result = beforeValue - afterValue;
    break;
  case Operator::Mult:
    result = beforeValue * afterValue;
    break;
  case Operator::Div:
    result = beforeValue / afterValue;
    break;

  default:
    error.setType(ErrorType::InvalidStructure);
    return error;
    break;
  }

  m_tokenList.erase(m_tokenList.begin() + position + 1);
  m_tokenList.erase(m_tokenList.begin() + position);
  m_tokenList[position - 1].setType(TokenType::NumericConstantT);
  m_tokenList[position - 1].setValue(result);

  return error;
}

std::vector<std::string> Lexer::splitString(const std::string &input)
{
  std::vector<std::string> fragments;
  std::string currentFragment;
  bool lastIsDigit = false;

  for (char c : input)
  {
    bool isDigitOrDot = (c >= '0' && c <= '9') || c == '.';

    if (isDigitOrDot == lastIsDigit)
    {
      currentFragment += c;
    }
    else
    {
      if (!currentFragment.empty())
      {
        fragments.push_back(currentFragment);
        currentFragment.clear();
      }
      currentFragment += c;
    }

    lastIsDigit = isDigitOrDot;
  }

  if (!currentFragment.empty())
  {
    fragments.push_back(currentFragment);
  }

  return fragments;
}

Error Lexer::tokenizeExpression()
{
  Error error;

  // Remove spaces from string
  std::string::iterator end_pos = std::remove(m_rawExpr.begin(), m_rawExpr.end(), ' ');
  m_rawExpr.erase(end_pos, m_rawExpr.end());

  if (m_rawExpr.size() == 0)
  {
    error.setType(ErrorType::InvalidStructure);
    return error;
  }

  m_splitExpr = Lexer::splitString(m_rawExpr);

  return error;
}

Error Lexer::startCompute()
{
  Error error;

  error = Lexer::tokenizeExpression();
  if (error.type())
    return error;

  for (const auto &str : m_splitExpr)
  {
    if (isNumber(str))
    {
      Token token;
      token.setType(TokenType::NumericConstantT);
      token.setValue(std::stof(str));
      m_tokenList.push_back(token);
    }
    else if (str == "")
      continue;
    else
    {
      Operator::Operator tokenOp;
      tokenOp = Lexer::getOperatorFromString((const std::string)str);
      if (tokenOp == Operator::Error)
      {
        error.setType(ErrorType::InvalidOperator);
        return error;
      }

      Token token;
      token.setType(TokenType::OperatorT);
      token.setOperator(tokenOp);
      m_tokenList.push_back(token);
    }
  }

  while (m_tokenList.size() > 1)
  {
    auto priorityOperationPos = Lexer::getPriorityOperator();
    error = Lexer::calculate(priorityOperationPos);
  }

  if (m_tokenList[0].type() == TokenType::OperatorT)
  {
    error.setType(ErrorType::InvalidStructure);
    return error;
  }

  std::cout << "Final result: " << m_tokenList[0].value() << std::endl;

  return error;
}