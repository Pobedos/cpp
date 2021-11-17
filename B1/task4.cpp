#include "tasks.hpp"
#include <iostream>
#include <vector>
#include <cstring>
#include "sort.hpp"
#include "strategy.hpp"
#include "supporting-things.hpp"

int mukhamadieva::task4(const char* order, size_t size)
{
  if (strcmp(order, "ascending") && strcmp(order, "descending"))
  {
    std::cerr << "Wrong order\n";
    return 1;
  }
  std::vector< double > vector(size);
  mukhamadieva::fillRandom(vector.data(), size);
  mukhamadieva::print(std::cout, vector);
  mukhamadieva::sort< mukhamadieva::StrategyOperator< double > >(vector, getSortMode(order));
  mukhamadieva::print(std::cout, vector);
  return 0;
}
