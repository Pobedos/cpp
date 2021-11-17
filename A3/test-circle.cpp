#include "test-functions.hpp"

BOOST_AUTO_TEST_SUITE(TestCircle)

BOOST_AUTO_TEST_CASE(testMove)
{
  const double startingRadius = 5.0;
  mukhamadieva::Circle circle(startingRadius, { 0.0, 0.0 });
  circle.move({ -5.1, 3.6 });
  double newRadius = circle.getFrameRect().height / 2;
  BOOST_CHECK_CLOSE(startingRadius, newRadius, mukhamadieva::TOLERANCE);
  circle.move(-5.1, 3.6);
  newRadius = circle.getFrameRect().height / 2;
  BOOST_CHECK_CLOSE(startingRadius, newRadius, mukhamadieva::TOLERANCE);
}

BOOST_AUTO_TEST_CASE(testArea)
{
  mukhamadieva::Circle circle(5.0, { 0.0, 0.0 });
  const double startingArea = circle.getArea();
  const double factor = 2.0;
  circle.scale(factor);
  const double newArea = circle.getArea();
  BOOST_CHECK_CLOSE(startingArea, newArea / (factor * factor), mukhamadieva::TOLERANCE);
}

BOOST_AUTO_TEST_CASE(testExceptions)
{
  BOOST_CHECK_THROW(mukhamadieva::Circle circle1(-3.0, { 5.0, 6.0 }), std::invalid_argument);
  mukhamadieva::Circle circle2(2.0, { 5.0, 6.0 });
  BOOST_CHECK_THROW(circle2.scale(-5.0), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
