#include <iostream>

#include "DynamicArray.h"

int main()
{
  // Test the constructor
  DynamicArray arr(1);

  // Test the pushBack method
  std::cout << "Push back 1" << std::endl;
  arr.pushBack(1);
  std::cout << "Size: " << arr.size() << std::endl;
  std::cout << "Capacity: " << arr.capacity() << std::endl;

  // Test the Resize method
  std::cout << "Push back 2" << std::endl;
  arr.pushBack(2);
  std::cout << "Size: " << arr.size() << std::endl;
  std::cout << "Capacity: " << arr.capacity() << std::endl;

  return 0;
}
