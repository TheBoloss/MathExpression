#include "Error.hpp"

Error::Error() : m_type(ErrorType::None), m_position(0) {}

ErrorType Error::type() const
{
  return m_type;
}

void Error::setType(const ErrorType type)
{
  m_type = type;
}

unsigned int Error::position() const
{
  return m_position;
}

void Error::setPosition(const unsigned int position)
{
  m_position = position;
}