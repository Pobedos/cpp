#include "supporting-things.hpp"
#include <random>
#include <ctime>
#include <cstring>

void mukhamadieva::fillRandom(double* array, int size)
{
  for (int i = 0; i < size; i++)
  {
    array[i] = (rand() * 1.0) / (RAND_MAX * 1.0) * 2 - 1;
  }
}

mukhamadieva::Order mukhamadieva::getSortMode(const char* order)
{
  if (!strcmp(order, "descending"))
  {
    return ORDER_DES;
  }
  if (!strcmp(order, "ascending"))
  {
    return ORDER_ASC;
  }
  return ORDER_ERROR;
}

bool mukhamadieva::checkForSpaces(const char* str)
{
  for (size_t i = 0; i < strlen(str); i++)
  {
    if (str[i] == ' ')
    {
      return true;
    }
  }
  return false;
}

bool mukhamadieva::checkIsNumber(const char* str)
{
  for (size_t i = 0; i < strlen(str); i++)
  {
    if (!std::isdigit(str[i]))
    {
      return false;
    }
  }
  return true;
}
