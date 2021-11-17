#include "circle.hpp"
#include <stdexcept>
#define _USE_MATH_DEFINES
#include <cmath>
#include "base-types.hpp"

mukhamadieva::Circle::Circle(const double radius, const point_t& position):
  radius_(radius),
  pos_(position)
{
  if (radius <= 0)
  {
    throw std::invalid_argument("Radius must be more than 0");
  }
}

double mukhamadieva::Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

mukhamadieva::rectangle_t mukhamadieva::Circle::getFrameRect() const
{
  return { radius_ * 2, radius_ * 2, pos_ };
}

void mukhamadieva::Circle::move(const point_t& position)
{
  pos_ = position;
}

void mukhamadieva::Circle::move(const double x, const double y)
{
  pos_.x += x;
  pos_.y += y;
}

void mukhamadieva::Circle::scale(const double factor)
{
  if (factor <= 0)
  {
    throw std::invalid_argument("Factor must be more than zero");
  }
  radius_ *= factor;
}
