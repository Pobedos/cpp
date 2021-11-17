#ifndef SHAPE_HPP
#define SHAPE_HPP

namespace mukhamadieva
{
  struct rectangle_t;
  struct point_t;

  class Shape
  {
  public:
    virtual ~Shape() = default;
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(const point_t& point) = 0;
    virtual void move(double dx, double dy) = 0;
    virtual void scale(double factor) = 0;
  };
}

#endif
