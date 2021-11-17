#include <iostream>
#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  point_t firstPosition = { 6.6, 6.4 };
  Shape* figure1 = new Rectangle(10.0, 10.0, firstPosition);
  Shape* figure2 = new Circle(5.5, firstPosition);
  Shape* figure3 = new Rectangle(15.6, 22.1, firstPosition);
  Shape* figure4 = new Circle(7.7, firstPosition);
  const int count = 4;
  Shape* array[count] = { figure1, figure2, figure3, figure4 };
  point_t temp = { 0.0, 0.0 };
  for (int i = 0; i < count; i++)
  {
    temp = array[i]->getPosition();
    std::cout << "Starting position; shape #" << i + 1 << ": ("
  << temp.x << ";" << temp.y << ")\n";
  }
  std::cout << "\n";
  std::cout << "\n\n";
  for (int i = 0; i < count; i++)
  {
    array[i]->move({ 6.4, 12.8 });
    temp = array[i]->getPosition();
    std::cout << "First move; shape #" << i + 1 << ": ("
  << temp.x << ";" << temp.y << ")\n";
  }
  std::cout << "\n\n";
  for (int i = 0; i < count; i++)
  {
    array[i]->move(11.11, 9.4);
    temp = array[i]->getPosition();
    std::cout << "Second move; shape #" << i + 1 << " : ("
  << temp.x << ";" << temp.y << ")\n";
  }
  std::cout << "\n\n";
  rectangle_t temp2 = array[0]->getFrameRect();
  for (int i = 0; i < count; i++)
  {
    temp2 = array[i]->getFrameRect();
    std::cout << "Rectangle №" << i + 1 << '\n'
  << "Height: "    << temp2.height << '\n'
  << "Width: "     << temp2.width << '\n'
  << "Position: (" << temp2.pos.x << ";" << temp2.pos.y << ")\n\n";
  }
  std::cout << "\n\n";
  // Deleting shapes!
  for (int i = 0; i < count; i++)
  {
    delete array[i];
  }
  return 0;
}
