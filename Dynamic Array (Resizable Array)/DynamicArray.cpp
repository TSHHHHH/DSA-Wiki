#include "DynamicArray.h"

#include <iostream>

DynamicArray::DynamicArray(int capacity)
    : _size(0), _capacity(capacity)
{
  _arr = new int[_capacity];
}

int DynamicArray::get(int index)
{
  return _arr[index];
}

void DynamicArray::set(int index, int value)
{
  // Check if the index is within the bounds of the array
  if (index < 0 || index >= _size)
  {
    std::cout << "Index out of bounds" << std::endl;
  }

  _arr[index] = value;
}

void DynamicArray::pushBack(int value)
{
  // Check if the array is full
  if (_size == _capacity)
  {
    Resize();
  }

  _arr[_size++] = value;
}

int DynamicArray::popBack()
{
  // if the array is not empty, decrease the size
  // PSA: This does not actually remove the element from the array
  // It just decreases the size, so the element is not accessible anymore
  // If the array is full, _arr[_size] will be overwritten by the next pushBack
  if (_size > 0)
    --_size;

  return _arr[_size];
}

void DynamicArray::Resize()
{
  // by default, double the capacity
  _capacity *= 2;

  // allocate a new array with the new capacity
  int *newArr = new int[_capacity];

  // copy the elements from the old array to the new array
  for (int i = 0; i < _size; ++i)
  {
    newArr[i] = _arr[i];
  }

  // delete the old array
  delete[] _arr;

  // point the old array to the new array
  _arr = newArr;
}

void DynamicArray::Resize(int newCapacity)
{
  // allocate a new array with the new capacity
  int *newArr = new int[newCapacity];

  // determine the size of the new array
  int newSize = _size < newCapacity ? _size : newCapacity;

  // copy the elements from the old array to the new array
  for (int i = 0; i < newSize; ++i)
  {
    newArr[i] = _arr[i];
  }

  // delete the old array
  delete[] _arr;

  // point the old array to the new array
  _arr = newArr;

  // update the capacity
  _capacity = newCapacity;
}

int DynamicArray::size()
{
  return _size;
}

int DynamicArray::capacity()
{
  return _capacity;
}
