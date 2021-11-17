#include "test-functions.hpp"

std::shared_ptr< mukhamadieva::Shape > mukhamadieva::makeRect()
{
  const double width = 3.0;
  const double height = 2.0;
  const mukhamadieva::point_t pos{ 9.0, 7.0 };
  return std::make_shared< mukhamadieva::Rectangle >(mukhamadieva::Rectangle(width, height, pos));
}

std::shared_ptr< mukhamadieva::Shape > mukhamadieva::makeCircle()
{
  const mukhamadieva::point_t pos{ 5.0, 8.0 };
  const double rad = 7.0;
  return std::make_shared< mukhamadieva::Circle >(mukhamadieva::Circle(rad, pos));
}
