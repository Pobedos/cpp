#include "test-functions.hpp"

BOOST_AUTO_TEST_SUITE(TestRectangle)

BOOST_AUTO_TEST_CASE(testMove)
{
  const double startingWidth = 5.0;
  const double startingHeight = 6.0;
  mukhamadieva::Rectangle rectangle(startingWidth, startingHeight, { 0.0, 0.0 });

  rectangle.move({ -5.1, 3.6 });
  double newWidth = rectangle.getFrameRect().width;
  double newHeight = rectangle.getFrameRect().height;
  BOOST_CHECK_CLOSE(startingWidth, newWidth, mukhamadieva::TOLERANCE);
  BOOST_CHECK_CLOSE(startingHeight, newHeight, mukhamadieva::TOLERANCE);

  rectangle.move(-5.1, 3.6);
  newWidth = rectangle.getFrameRect().width;
  newHeight = rectangle.getFrameRect().height;

  BOOST_CHECK_CLOSE(startingWidth, newWidth, mukhamadieva::TOLERANCE);
  BOOST_CHECK_CLOSE(startingHeight, newHeight, mukhamadieva::TOLERANCE);
}

BOOST_AUTO_TEST_CASE(testArea)
{
  mukhamadieva::Rectangle rectangle(5.0, 6.0, { 0.0, 0.0 });
  const double startingArea = rectangle.getArea();
  const double factor = 2.0;
  rectangle.scale(factor);
  const double newArea = rectangle.getArea();

  BOOST_CHECK_CLOSE(startingArea, newArea / (factor * factor), mukhamadieva::TOLERANCE);
}

BOOST_AUTO_TEST_CASE(testExceptions)
{
  BOOST_CHECK_THROW(mukhamadieva::Rectangle rect1(-2.0, 5.0, { 5.0, 6.0 }), std::invalid_argument);
  BOOST_CHECK_THROW(mukhamadieva::Rectangle rect2(2.0, -5.0, { 5.0, 6.0 }), std::invalid_argument);

  mukhamadieva::Rectangle rect3(2.0, 5.0, { 5.0, 6.0 });

  BOOST_CHECK_THROW(rect3.scale(-5.0), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
