#include "Token.hpp"

TokenType Token::type() const
{
  return m_type;
}

void Token::setType(TokenType type)
{
  m_type = type;
}

float Token::value() const
{
  return m_value;
}

void Token::setValue(float value_)
{
  m_value = value_;
}

Operator::Operator Token::getOperator() const
{
  return m_operator;
}

void Token::setOperator(const Operator::Operator &type_)
{
  m_operator = type_;
}
