#include <iostream>
#include "tasks.hpp"

int main(int argc, char *argv[])
{
  if (argc != 2) {
    std::cerr << "Invalid arguments";
    return 1;
  }
  std::string task = argv[1];
  if (task == "1")
  {
    return mukhamadieva::bookTask(std::cin, std::cout);
  }
  else if (task == "2")
  {
    return mukhamadieva::containerTask(std::cout);
  }
  else
  {
    std::cerr << "Invalid task number";
    return 1;
  }
}
