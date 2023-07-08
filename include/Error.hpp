#ifndef ERROR_HPP
#define ERROR_HPP

enum ErrorType
{
  None,
  Unknown,
  InvalidStructure,
  InvalidOperator,
};

class Error
{
private:
  ErrorType m_type;
  unsigned int m_position;

public:
  Error();

  ErrorType type() const;
  void setType(const ErrorType type);

  unsigned int position() const;
  void setPosition(const unsigned int position);
};

#endif