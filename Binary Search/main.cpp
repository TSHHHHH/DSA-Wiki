#include <iostream>

#include "BS.h"

int main()
{
  std::vector<int> nums = {1, 3, 5, 6};
  int target = 5;

  std::cout << BinarySearch(nums, target, 0, nums.size() - 1) << std::endl;

  return 0;
}