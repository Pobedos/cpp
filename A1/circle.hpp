#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include <iostream>
#include "shape.hpp"
#include "base-types.hpp"

class Circle: public Shape
{
public:
  Circle(double radius_, point_t& position);
  double getArea() const;
  rectangle_t getFrameRect() const;
  void move(const point_t& position);
  void move(const double x, const double y);
  point_t getPosition() const;
private:
  double radius_;
  point_t pos_;
};

#endif
