class DynamicArray
{
private:
  int *_arr;

  int _size;
  int _capacity;

public:
  DynamicArray(int capacity);

  int get(int index);

  void set(int index, int value);

  void pushBack(int value);

  int popBack();

  void Resize();
  void Resize(int newCapacity);

  int size();
  int capacity();
};