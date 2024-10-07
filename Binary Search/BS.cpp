#include "BS.h"

int BinarySearch(std::vector<int> &nums, int target, int left, int right)
{
  if(left > right)
    return -1;
    
  int mid = (left + right) / 2;

  if(nums[mid] > target)
    return BinarySearch(nums, target, left, mid - 1);
  else if (nums[mid] < target)
    return BinarySearch(nums, target, mid + 1, right);
  else
    return mid;
}
