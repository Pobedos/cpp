#include "container.hpp"
#include <cassert>

namespace mukhamadieva
{

  constexpr Container::ValueType factorial(Container::ValueType n)
  {
    return (n <= 1) ? 1 : (n * factorial(n - 1));
  }
  constexpr Container::ValueType beginMultiplier = 1;
  constexpr Container::ValueType beginValue = factorial(beginMultiplier);
  constexpr Container::ValueType endMultiplier = 11;
  constexpr Container::ValueType endValue = factorial(endMultiplier);

}

mukhamadieva::Container::Iterator::Iterator():
  value_(0),
  multiplier_(0)
{}

mukhamadieva::Container::Iterator::Iterator(ValueType value, ValueType multiplier):
  value_(value),
  multiplier_(multiplier)
{}

const mukhamadieva::Container::ValueType& mukhamadieva::Container::Iterator::operator*() const
{
  assert(value_ != 0);
  return value_;
}

const mukhamadieva::Container::ValueType* mukhamadieva::Container::Iterator::operator->() const
{
  assert(value_ != 0);
  return &value_;
}

mukhamadieva::Container::Iterator& mukhamadieva::Container::Iterator::operator++()
{
  assert(multiplier_ < endMultiplier);
  value_ *= ++multiplier_;
  return *this;
}

mukhamadieva::Container::Iterator mukhamadieva::Container::Iterator::operator++(int)
{
  Iterator temp = *this;
  ++(*this);
  return temp;
}

mukhamadieva::Container::Iterator& mukhamadieva::Container::Iterator::operator--()
{
  assert(multiplier_ > beginMultiplier);
  value_ /= multiplier_--;
  return *this;
}

mukhamadieva::Container::Iterator mukhamadieva::Container::Iterator::operator--(int)
{
  Iterator temp = *this;
  --(*this);
  return temp;
}

bool mukhamadieva::Container::Iterator::operator==(const Container::Iterator& other) const
{
  return **this == *other;
}

bool mukhamadieva::Container::Iterator::operator!=(const Container::Iterator& other) const
{
  return !(*this == other);
}

mukhamadieva::Container::Iterator mukhamadieva::Container::begin() const noexcept
{
  return { beginValue, beginMultiplier };
}

mukhamadieva::Container::Iterator mukhamadieva::Container::end() const noexcept
{
  return { endValue, endMultiplier };
}

