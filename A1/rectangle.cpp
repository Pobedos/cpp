#include "rectangle.hpp"
#include <cassert>
#include "base-types.hpp"

Rectangle::Rectangle(double width, double height, point_t& pos):
  width_(width),
  height_(height),
  pos_(pos)
{
  assert(width_ >= 0);
  assert(height_ >= 0);
}

double Rectangle::getArea() const
{
  return height_ * width_;
}

rectangle_t Rectangle::getFrameRect() const
{
  return { width_, height_, pos_ };
}

void Rectangle::move(const point_t& position)
{
  pos_ = position;
}

void Rectangle::move(const double x, const double y)
{
  pos_.x += x;
  pos_.y += y;
}

point_t Rectangle::getPosition() const
{
  return pos_;
}
