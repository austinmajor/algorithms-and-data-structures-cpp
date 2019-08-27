#include <iostream>

using namespace std;

class DynamicArray{
private:
  // Member variables
  int * arr;
  int size;

public:
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
  // DynamicArray(const DynamicArray&)

  // Destructor
  ~DynamicArray()
  {
    // for loop delete arr[i]
    cout << "Destructor called" << endl;
  }

  // Member Functions
  void fillArray()
  {
    int i;
    for(i = 0; i < size; i++)
    {
      arr[i] = rand() % 9;
    }
  }

  void sortArray()
  {
    int i, j;
    for(i = 1; i < size; i++)
    {
      for(j = i; j > 0 && arr[j] < arr[j-1]; j--)
      {
        swap(arr[j], arr[j-1]);
      }
    }
  }

  void printArray()
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
  DynamicArray a;
  a.fillArray();
  a.sortArray();
  a.printArray();

  return 0;
}