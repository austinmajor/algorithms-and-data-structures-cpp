// Author: Austin Major
// Title: Insertion Sort with a Dynamic Array Class
// Date: 8/22/19
#include <iostream>

using namespace std;

class DynamicArray
{
private:
  // Member variables
  // An int pointer to hold a dynamically allocated array
  int *arr;

  // Holds the size of the array
  int size;

public:
  // Default Constructor
  // Allocates an array of size 10
  DynamicArray()
  {
    this->size = 10;
    this->arr = new int[size];
  }

  // Paramterized Constructor
  // Retrieves the size and uses the size to allocate an array
  DynamicArray(int size)
  {
    this->size = size;
    this->arr = new int[size];
  }

  // Copy Constructor
  // Performs deep copy
  // Not sure on this
  // this->size
  DynamicArray(const DynamicArray &obj)
  {
    size = obj.size;
    arr = new int[size];
    for (int i = 0; i < size; i++)
    {
      arr[i] = obj.arr[i];
    }
  }

  // Copy Assignment Operator
  // Performs a deep copy and supports self-assignment of the form x = x
  // https://stackoverflow.com/questions/4172722/what-is-the-rule-of-three

  // Destructor
  // Recycles allocated memory
  ~DynamicArray()
  {
    // for loop delete arr[i]
    // not sure on this syntax
    delete[] arr;
  }

  // Member Functions
  // Fills array with random #'s from 0-9
  // This -> size ??
  void fillArray()
  {
    int i;
    for (i = 0; i < size; i++)
    {
      arr[i] = rand() % 9;
    }
  }

  // Insertion Sort
  // Complexity: O(n^2)
  // this -> size ??
  void sortArray()
  {
    int i, j;
    for (i = 1; i < size; i++)
    {
      for (j = i; j > 0 && arr[j] < arr[j - 1]; j--)
      {
        swap(arr[j], arr[j - 1]);
      }
    }
  }

  // Prints all elements in the array
  // this -> size ??
  void printArray()
  {
    int i;
    for (i = 0; i < size; i++)
    {
      cout << arr[i] << " ";
    }
  }
};

int main()
{
  DynamicArray a;
  a.fillArray();
  a.sortArray();
  a.printArray();

  return 0;
}