#ifndef BOOK_USER_INTERFACE_HPP
#define BOOK_USER_INTERFACE_HPP

#include <string>
#include <vector>
#include "book.hpp"

namespace mukhamadieva
{

  int executeUserInterface(Book& book, std::vector< std::string > args, std::ostream& out);

}

#endif
