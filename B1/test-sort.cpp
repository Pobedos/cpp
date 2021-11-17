#include <boost/test/unit_test.hpp>
#include <vector>
#include <random>
#include <forward_list>
#include "supporting-things.hpp"
#include "sort.hpp"
#include "strategy.hpp"

BOOST_AUTO_TEST_SUITE(test)

BOOST_AUTO_TEST_CASE(testSort)
{
  srand(time(0));
  const size_t size = 3;
  const char* order = "ascending";
  mukhamadieva::Order ord = mukhamadieva::getSortMode(order);
  std::vector< int > vector1(size);
  std::vector< int > vector2(size);
  std::forward_list< int > list(size);

  std::generate(vector1.begin(), vector1.end(), rand);
  std::generate(vector2.begin(), vector2.end(), rand);
  std::generate(list.begin(), list.end(), rand);

  mukhamadieva::sort< mukhamadieva::StrategyOperator< int > >(vector1, ord);
  mukhamadieva::sort< mukhamadieva::StrategyAt< int > >(vector2, ord);
  mukhamadieva::sort< mukhamadieva::StrategyIter< int > >(list, ord);

  BOOST_CHECK(std::is_sorted(vector1.begin(), vector1.end()));
  BOOST_CHECK(std::is_sorted(vector2.begin(), vector2.end()));
  BOOST_CHECK(std::is_sorted(list.begin(), list.end()));
}

BOOST_AUTO_TEST_SUITE_END()
