#include "circle.hpp"
#include <cassert>
#include <cmath>
#include "base-types.hpp"

Circle::Circle(double radius, point_t& position):
  radius_(radius),
  pos_(position)
{
  assert(radius_ >= 0);
}

double Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

rectangle_t Circle::getFrameRect() const
{
  return { radius_ * 2, radius_ * 2, pos_ };
}

void Circle::move(const point_t& position)
{
  pos_ = position;
}

void Circle::move(const double x, const double y)
{
  pos_.x += x;
  pos_.y += y;
}

point_t Circle::getPosition() const
{
  return pos_;
}
