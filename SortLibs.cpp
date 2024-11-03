#include "SortLibs.h"

void SortLibs::SelectionSort(std::vector<int> &vec, int size)
{
  // step stops at size - 1 because the last element is already sorted
  for (int step = 0; step < size - 1; ++step)
  {
    // assume the minimum element is the first element
    int minIdx = step;

    // i starts from the element after the step
    for (int i = step + 1; i < size; ++i)
    {
      // find the minimum element
      if (vec[i] < vec[minIdx])
      {
        minIdx = i;
      }
    }

    // swap the minimum element with the first element
    if (minIdx != step)
    {
      std::swap(vec[step], vec[minIdx]);
    }
  }
}

void SortLibs::InsertionSort(std::vector<int> &vec, int size)
{
  for (int step = 1; step < size; ++step)
  {
    // cache the key in the current step
    int key = vec[step];

    // j is the index before the current step
    int j = step - 1;

    // move elements of vec[0..j] that are greater than key to one position ahead of their current position
    // it loops from the back to the front is because we need to shift the elements to the right, otherwise, we will lose the elements
    while (j >= 0 && vec[j] > key)
    {
      // move the element to the next position
      vec[j + 1] = vec[j];

      // move j to the previous element
      --j;
    }

    // insert the key in the correct position
    vec[j + 1] = key;
  }
}

void SortLibs::BubbleSort(std::vector<int> &vec, int size)
{
  // step stops at size - 1 because the last element is already sorted
  for (int step = 0; step < size - 1; ++step)
  {
    // swapped is used to check if any elements were swapped in the inner loop
    bool swapped = false;

    // loop through the array from 0 to size - step - 1
    // because the right side of the array is already sorted
    for (int i = 0; i < size - step - 1; ++i)
    {
      // swap if the element found is greater than the next element
      if (vec[i] > vec[i + 1])
      {
        std::swap(vec[i], vec[i + 1]);

        swapped = true;
      }
    }

    // if no two elements were swapped by the inner loop, then the array is already sorted
    if (!swapped)
    {
      break;
    }
  }
}

void SortLibs::Merge(std::vector<int> &vec, int left, int mid, int right)
{
  // the size of left subarray
  int vecSize_left = mid - left + 1;
  // the size of right subarray
  int vecSize_right = right - mid;

  // create temporary vectors
  std::vector<int> leftVec(vecSize_left), rightVec(vecSize_right);

  // copy data to temporary vectors leftVec and rightVec
  for (int i = 0; i < vecSize_left; ++i)
  {
    leftVec[i] = vec[left + i];
  }
  for (int j = 0; j < vecSize_right; ++j)
  {
    rightVec[j] = vec[(mid + 1) + j];
  }

  // initialize the markers for the left, right, and merged vectors for merging
  int leftVecMarker = 0;
  int rightVecMarker = 0;
  int mergedVecMarker = left;

  // merge the temporary vectors back into vec[left..right]
  while (leftVecMarker < vecSize_left && rightVecMarker < vecSize_right)
  {
    // if the leftVec element is less than or equal to the rightVec element
    if (leftVec[leftVecMarker] <= rightVec[rightVecMarker])
    {
      vec[mergedVecMarker] = leftVec[leftVecMarker];
      ++leftVecMarker;
    }
    // if the rightVec element is less than the leftVec element
    else
    {
      vec[mergedVecMarker] = rightVec[rightVecMarker];
      ++rightVecMarker;
    }

    // move to the next position
    ++mergedVecMarker;
  }

  // copy the remaining elements of leftVec[] if there are any
  while (leftVecMarker < vecSize_left)
  {
    vec[mergedVecMarker] = leftVec[leftVecMarker];
    ++leftVecMarker;
    ++mergedVecMarker;
  }

  // copy the remaining elements of rightVec[] if there are any
  while (rightVecMarker < vecSize_right)
  {
    vec[mergedVecMarker] = rightVec[rightVecMarker];
    ++rightVecMarker;
    ++mergedVecMarker;
  }
}

void SortLibs::MergeSort(std::vector<int> &vec, int left, int right)
{
  if (left < right)
  {
    int middle = left + (right - left) / 2;

    MergeSort(vec, left, middle);
    MergeSort(vec, middle + 1, right);

    Merge(vec, left, middle, right);
  }
}

int SortLibs::Partition(std::vector<int> &vec, int left, int right)
{
  // Select a random pivot and swap it with the first element
  int random_pivot = left + rand() % (right - left + 1);
  std::swap(vec[left], vec[random_pivot]);

  int pivot = vec[left]; // Choose the pivot element
  
  int low = left + 1;    // Start right after the pivot
  int high = right;

  while (low <= high)
  {
    // Find elements larger than the pivot
    while (low <= right && vec[low] <= pivot)
    {
      ++low;
    }

    // Find elements smaller than the pivot
    while (high >= left && vec[high] > pivot)
    {
      --high;
    }

    // Swap elements if low and high haven't crossed
    if (low < high)
    {
      std::swap(vec[low], vec[high]);
    }
  }

  // Place the pivot in the correct position (swap with high)
  std::swap(vec[left], vec[high]);

  // Return the position of the pivot
  return high;
}

void SortLibs::QuickSort(std::vector<int> &vec, int low, int high)
{
  if (low < high)
  {
    int pivot = Partition(vec, low, high);

    QuickSort(vec, low, pivot - 1);
    QuickSort(vec, pivot + 1, high);
  }
}
