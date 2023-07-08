#ifndef TYPES_HPP
#define TYPES_HPP

#include <string>
#include <map>

enum TokenType
{
  NumericConstantT,
  OperatorT,
};

namespace Operator
{
  enum Operator
  {
    Error,
    Add,
    Sub,
    Mult,
    Div,
  };
}

#endif