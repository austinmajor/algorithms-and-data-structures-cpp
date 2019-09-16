#include <iostream>
#include <cstdlib>
#include <ctime>

#include "ArrayList.h"

// RandFill is a helper function to randomly fill an ArrayList.
void RandFill(ArrayList&, int, int);

int main()
{
    // Seed random once at the start of the program.
    srand(time(NULL));

    ArrayList a;

    std::cout << "ArrayList Defaults:" << std::endl << "Size: " << a.size() << std::endl << "Capacity: " << a.capacity() << std::endl << "Elements: " << a.print() << std::endl << std::endl;

    RandFill(a, 11, 100);

    std::cout << "ArrayList After Randomly Adding 11 Elements:" << std::endl << "Size: " << a.size() << std::endl << "Capacity: " << a.capacity() << std::endl << "Elements: " << a.print() << std::endl << std::endl;

    a.add(0, 101);

    std::cout << "ArrayList After Adding an Element (101) at Index 0:" << std::endl << "Size: " << a.size() << std::endl << "Capacity: " << a.capacity() << std::endl << "Elements: " << a.print() << std::endl << std::endl;

    a.set(0, 102);

    std::cout << "ArrayList After Setting Index 0 to 102:" << std::endl << "Size: " << a.size() << std::endl << "Capacity: " << a.capacity() << std::endl << "Elements: " << a.print() << std::endl << std::endl;

    int popped = a.pop();

    std::cout << "ArrayList After Popping Last Element Off:" << std::endl << "Size: " << a.size() << std::endl << "Capacity: " << a.capacity() << std::endl << "Elements: " << a.print() << std::endl << "Popped Element: " << popped << std::endl << std::endl;

    a.push_back(103);

    std::cout << "ArrayList After Pushing Back an Element (103):" << std::endl << "Size: " << a.size() << std::endl << "Capacity: " << a.capacity() << std::endl << "Elements: " << a.print() << std::endl << std::endl;

    a.del(0);

    std::cout << "ArrayList After Deleting Index 0:" << std::endl << "Size: " << a.size() << std::endl << "Capacity: " << a.capacity() << std::endl << "Elements: " << a.print() << std::endl;

    return 0;
}

void RandFill(ArrayList &a, int count, int bound)
{
    for(int i = 0; i < count; i++)
    {
        a.add(rand() % bound);
    }
}