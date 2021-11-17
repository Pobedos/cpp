#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "dataStruct.hpp"

int main()
{
  std::vector< mukhamadieva::DataStruct > v;
  std::copy(std::istream_iterator< mukhamadieva::DataStruct >(std::cin), std::istream_iterator< mukhamadieva::DataStruct >(), std::back_inserter(v));
  if (!std::cin.eof())
  {
    return 1;
  }
  std::sort(v.begin(), v.end());
  std::copy(v.begin(), v.end(), std::ostream_iterator< mukhamadieva::DataStruct >(std::cout, "\n"));
  return 0;
}
