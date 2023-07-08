#ifndef TOKEN_HPP
#define TOKEN_HPP

#include "types.hpp"

class Token
{
private:
  TokenType m_type;
  float m_value;
  Operator::Operator m_operator;

public:
  TokenType type() const;
  void setType(TokenType type);
  float value() const;
  void setValue(float value_);
  Operator::Operator getOperator() const;
  void setOperator(const Operator::Operator &type_);
};

class NumericConstantToken : public Token
{
private:
  float m_value;

public:
  NumericConstantToken();
  float value() const;
  void setValue(float value_);
};

class OperatorToken : public Token
{
private:
  Operator::Operator m_operator;
  unsigned int m_priority;

public:
  OperatorToken();
  Operator::Operator getOperator() const;
  void setOperator(const Operator::Operator &type_);

  unsigned int priority() const;
  void setPriority(unsigned int priority);
};

#endif