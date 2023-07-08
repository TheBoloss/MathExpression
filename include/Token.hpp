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

#endif