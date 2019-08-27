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
    this->arr = new int[this->size];
  }

  // Paramterized Constructor
  // Retrieves the size and uses it to allocate an array
  DynamicArray(int size)
  {
    this->size = size;
    this->arr = new int[size];
  }

  // Copy Constructor
  // Performs deep copy
  DynamicArray(const DynamicArray &obj)
  {
    this->size = obj.size;
    this->arr = new int[this->size];
    for (int i = 0; i < this->size; i++)
    {
      this->arr[i] = obj.arr[i];
    }
  }

  // Copy Assignment Operator
  // Performs a deep copy and supports self-assignment of the form x = x
  // DynamicArray::operator=(const DynamicArray &obj)
  // {
  //   if (this != &obj)
  //   {
  //     arr = new int[obj.size];
  //     size = obj.size;
  //     for (int i = 0; i < size; i++)
  //       arr[i] = obj.arr[i];
  //   }
  //   return *this;
  // }

  // Destructor
  // Recycles allocated memory
  ~DynamicArray()
  {
    delete[] this->arr;
  }

  // Member Function
  // Fills array with random #'s from 0-9
  void FillArray()
  {
    for (int i = 0; i < this->size; i++)
    {
      this->arr[i] = rand() % 9;
    }
  }

  // Member Function
  // Insertion Sort
  // Complexity: O(n^2)
  void SortArray()
  {
    for (int i = 1; i < this->size; i++)
    {
      for (int j = i; j > 0 && this->arr[j] < this->arr[j - 1]; j--)
      {
        swap(this->arr[j], this->arr[j - 1]);
      }
    }
  }

  // Member Function
  // Prints all elements in the array
  void PrintArray()
  {
    for (int i = 0; i < this->size; i++)
    {
      cout << this->arr[i] << " ";
    }
  }
};

int main()
{
  DynamicArray a;
  a.FillArray();
  a.SortArray();
  a.PrintArray();

  return 0;
}