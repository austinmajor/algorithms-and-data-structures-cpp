#include <iostream>

using namespace std;

class DynamicArray{
public:
  // Member variables
  // these need to be private
  int * arr;
  int size;

  // Default Constructor
  DynamicArray()
  {
    arr = new int[10];
  }

  // Paramterized Constructor
  DynamicArray(int size)
  {
    arr = new int[size];
  }
  
  // Copy Constructor
  DynamicArray(int * d)
  {
    *arr = *d;
  }

  // Copy Assignment Operator
  DynamicArray(const DynamicArray&)

  // Destructor
  ~DynamicArray()
  {
    cout << "Destructor called" << endl;
  }

  // Member Functions
  void fill()
  {
    int i;
    for(i = 0; i < 10; i++)
    {
      arr[i] = rand();
    }
  }

  void sort()
  {
    int i, j;
    for(i = 1; i < n; i++)
    {
      for(j = i; j > 0 && arr[j] < arr[j-1]; j--)
      {
        swap(arr[j], arr[j-1]);
        printArray(arr, n);
      }
    }
  }

  void print(int size)
  {
    int i;
    for(i = 0; i < size; i++)
    {
      cout << arr[i] << " ";
    }
  }
};

int main()
{

  return 0;
}