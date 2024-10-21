#include <iostream>
#include <vector>

namespace SortLibs
{
  /// @brief Selection sort algorithm
  /// @param vec The vector to be sorted
  /// @param size The size of the vector
  void SelectionSort(std::vector<int>& vec, int size);

  /// @brief Insertion sort algorithm 
  /// @param vec The vector to be sorted
  /// @param size The size of the vector
  void InsertionSort(std::vector<int>& vec, int size);

  /// @brief Bubble sort algorithm.
  ///        The algorithm compares each pair of adjacent elements in the vector and swaps them if they are in the wrong order.
  /// @param vec The vector to be sorted
  /// @param size The size of the vector
  void BubbleSort(std::vector<int>& vec, int size);

#pragma region MergeSort

  /// @brief Merge function for merge sort
  /// @param vec The vector to be sorted
  /// @param left The left index of the vector
  /// @param mid The middle index of the vector
  /// @param right The right index of the vector
  void Merge(std::vector<int>& vec, int left, int mid, int right);

  /// @brief The merge sort algorithm.
  ///        The algorithm divides the input array into two halves, recursively sorts the two halves, and then merges the sorted halves.
  /// @param vec The vector to be sorted
  /// @param left The left index of the vector
  /// @param right The right index of the vector
  void MergeSort(std::vector<int>& vec, int left, int right);

#pragma endregion

#pragma region QuickSort

  int Partition(std::vector<int>& vec, int low, int high);

  void QuickSort(std::vector<int>& vec, int low, int high);

#pragma endregion
}