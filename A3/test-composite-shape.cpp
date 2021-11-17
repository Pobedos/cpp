#include "test-functions.hpp"

BOOST_AUTO_TEST_SUITE(TestCompositeShape)

BOOST_AUTO_TEST_CASE(testMove)
{
  std::shared_ptr< mukhamadieva::Shape > circle = mukhamadieva::makeCircle();
  std::shared_ptr< mukhamadieva::Shape > rectangle = mukhamadieva::makeRect();
  mukhamadieva::CompositeShape comp{circle, rectangle};
  const double startingRectWidth = comp.getFrameRect().width;
  const double startingRectHeight = comp.getFrameRect().height;
  comp.move({ -5.1, 3.6 });

  BOOST_CHECK_CLOSE(startingRectWidth, comp.getFrameRect().width, mukhamadieva::TOLERANCE);
  BOOST_CHECK_CLOSE(startingRectHeight, comp.getFrameRect().height, mukhamadieva::TOLERANCE);
  comp.move(5.0, 3.5);

  BOOST_CHECK_CLOSE(startingRectWidth, comp.getFrameRect().width, mukhamadieva::TOLERANCE);
  BOOST_CHECK_CLOSE(startingRectHeight, comp.getFrameRect().height, mukhamadieva::TOLERANCE);
}

BOOST_AUTO_TEST_CASE(testArea)
{
  std::shared_ptr< mukhamadieva::Shape > circle = mukhamadieva::makeCircle();
  std::shared_ptr< mukhamadieva::Shape > rectangle = mukhamadieva::makeRect();
  mukhamadieva::CompositeShape comp{circle, rectangle};
  const double startingArea = comp.getArea();
  const double factor = 2.0;
  comp.scale(factor);

  BOOST_CHECK_CLOSE(startingArea, comp.getArea() / (factor * factor), mukhamadieva::TOLERANCE);
}

BOOST_AUTO_TEST_CASE(testCopy)
{
  std::shared_ptr< mukhamadieva::Shape > circle = mukhamadieva::makeCircle();
  std::shared_ptr< mukhamadieva::Shape > rectangle = mukhamadieva::makeRect();
  mukhamadieva::CompositeShape comp1{circle, rectangle};
  mukhamadieva::CompositeShape comp2(comp1);
  BOOST_CHECK_CLOSE(comp1.getFrameRect().height, comp2.getFrameRect().height, mukhamadieva::TOLERANCE);
}

BOOST_AUTO_TEST_CASE(testCopy2)
{
  std::shared_ptr< mukhamadieva::Shape > circle = mukhamadieva::makeCircle();
  std::shared_ptr< mukhamadieva::Shape > rectangle = mukhamadieva::makeRect();
  mukhamadieva::CompositeShape comp1{circle, rectangle};
  mukhamadieva::CompositeShape comp2 = std::move(comp1);
  BOOST_CHECK_CLOSE(comp2.getFrameRect().height, comp2.getFrameRect().height, mukhamadieva::TOLERANCE);
}

BOOST_AUTO_TEST_CASE(testInsert)
{
  std::shared_ptr< mukhamadieva::Shape > circle = mukhamadieva::makeCircle();
  std::shared_ptr< mukhamadieva::Shape > rectangle = mukhamadieva::makeRect();
  mukhamadieva::CompositeShape comp{circle, rectangle};
  std::shared_ptr< mukhamadieva::Shape > circle2 = mukhamadieva::makeCircle();
  BOOST_CHECK_NO_THROW(comp.insert(circle2));
}

BOOST_AUTO_TEST_CASE(testRemove)
{
  std::shared_ptr< mukhamadieva::Shape > circle = mukhamadieva::makeCircle();
  std::shared_ptr< mukhamadieva::Shape > rectangle = mukhamadieva::makeRect();
  mukhamadieva::CompositeShape comp{circle, rectangle};
  BOOST_CHECK_NO_THROW(comp.remove(1));
}
BOOST_AUTO_TEST_SUITE_END()
