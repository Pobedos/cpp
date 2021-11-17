#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <iostream>
#include "base-types.hpp"
#include "shape.hpp"

class Rectangle: public Shape
{
public:
  Rectangle(double width, double height, point_t& pos);
  double getArea() const;
  rectangle_t getFrameRect() const;
  void move(const point_t& position);
  void move(const double x, const double y);
  point_t getPosition() const;
private:
  double width_;
  double height_;
  point_t pos_;
};

#endif
