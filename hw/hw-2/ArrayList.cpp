#include <algorithm>
#include <string>
#include <sstream>

#include "ArrayList.h"
#include "Car.h"

template <class Generic>
bool ArrayList<Generic>::_isFull()
{
    if (this->_size >= this->_capacity)
    {
        return true;
    }

    return false;
}

template <class Generic>
void ArrayList<Generic>::_increaseCapacity()
{
    this->_capacity = this->_capacity * 2;

    Generic *temp = new (std::nothrow) Generic[this->_capacity];
    if (!temp)
    {
        throw "failed to dynamically allocate memory";
    }

    for (int i = 0; i < this->_size; i++)
    {
        temp[i] = this->_arr[i];
    }

    delete[] this->_arr;
    this->_arr = temp;
}

template <class Generic>
ArrayList<Generic>::ArrayList() : _capacity(10), _size(0)
{
    this->_arr = new (std::nothrow) Generic[this->_capacity];
    if (!this->_arr)
    {
        throw "failed to dynamically allocate memory for given size";
    }
}

template <class Generic>
ArrayList<Generic>::ArrayList(int capacity) : _capacity(capacity), _size(0)
{
    if (capacity > 0)
    {
        this->_arr = new (std::nothrow) Generic[this->_capacity];
        if (!this->_arr)
        {
            throw "failed to dynamically allocate memory for given size";
        }

        return;
    }

    // If an invalid capacity was given, use default constructor.
    ArrayList();
}

template <class Generic>
ArrayList<Generic>::ArrayList(const ArrayList &that) : _capacity(that._capacity), _size(that._size)
{
    this->_arr = new (std::nothrow) Generic[this->_capacity];
    if (!this->_arr)
    {
        throw "failed to dynamically allocate memory for given size";
    }

    for (int i = 0; i < this->_size; i++)
    {
        this->_arr[i] = that._arr[i];
    }
}

template <class Generic>
ArrayList<Generic> &ArrayList<Generic>::operator=(const ArrayList &that)
{
    if (this != &that)
    {
        this->_capacity = that._capacity;
        this->_size = that._size;

        this->_arr = new (std::nothrow) Generic[this->_capacity];
        if (!this->_arr)
        {
            throw "failed to dynamically allocate memory";
        }

        for (int i = 0; i < this->_size; i++)
        {
            this->_arr[i] = that._arr[i];
        }
    }

    return *this;
}

template <class Generic>
ArrayList<Generic>::~ArrayList()
{
    delete[] this->_arr;
}

template <class Generic>
int ArrayList<Generic>::size()
{
    return this->_size;
}

template <class Generic>
int ArrayList<Generic>::capacity()
{
    return this->_capacity;
}

template <class Generic>
void ArrayList<Generic>::add(Generic element)
{
    if (this->_isFull())
        this->_increaseCapacity();

    this->_arr[this->_size] = element;
    this->_size++;
}

template <class Generic>
void ArrayList<Generic>::add(int index, Generic element)
{
    if (index < 0 || index > this->_size)
    {
        throw "index out of valid range";
    }

    if (this->_isFull())
        this->_increaseCapacity();

    // If the element is essentially being added to the end.
    if (index == this->_size)
    {
        this->add(element);
        return;
    }

    // Shift all elements forward from the last element to the desired
    // index.
    for (int i = this->_size - 1; i >= index; i--)
    {
        this->_arr[i + 1] = this->_arr[i];
    }

    // Set the element at the index (nothing is there now) and increment
    // the size.
    this->_arr[index] = element;
    this->_size++;
}

template <class Generic>
void ArrayList<Generic>::push_back(Generic element)
{
    this->add(element);
}

template <class Generic>
void ArrayList<Generic>::set(int index, Generic element)
{
    if (index < 0 || index >= this->_size)
    {
        throw "invalid index given";
    }

    this->_arr[index] = element;
}

template <class Generic>
Generic ArrayList<Generic>::get(int index)
{
    if (index < 0 || index >= this->_size)
    {
        throw "invalid index given";
    }

    return this->_arr[index];
}

template <class Generic>
void ArrayList<Generic>::del(int index)
{
    if (index < 0 || index >= this->_size)
    {
        throw "invalid index given";
    }

    Generic *temp = new (std::nothrow) Generic[this->_capacity];
    if (!temp)
    {
        throw "unable to allocate memory for dynamic array";
    }

    // Copy up to index.
    for (int i = 0; i < index; i++)
    {
        temp[i] = this->_arr[i];
    }

    // Decrement size and copy everything (with an offset) after index.
    this->_size--;
    for (int i = index; i < this->_size; i++)
    {
        temp[i] = this->_arr[i + 1];
    }

    delete[] this->_arr;
    this->_arr = temp;
}

template <class Generic>
Generic ArrayList<Generic>::pop()
{
    if (this->_size == 0)
    {
        throw "no elements exist to pop off";
    }

    Generic *temp = new (std::nothrow) Generic[this->_capacity];
    if (!temp)
    {
        throw "error allocating memory for dynamic array";
    }

    for (int i = 0; i < this->_size - 1; i++)
    {
        temp[i] = this->_arr[i];
    }

    // Capture popped value to return.
    Generic popped = this->_arr[this->_size - 1];

    // Delete backing array, replace with new one, and decrement size.
    delete[] this->_arr;
    this->_arr = temp;
    this->_size--;

    return popped;
}

template <>
std::string ArrayList<car::Model>::print()
{
    std::stringstream ss;

    for (int i = 0; i < this->_size; i++)
    {
        ss << car::PrintModel(this->_arr[i]) << std::endl;
    }

    return ss.str();
}

template <>
car::Model ArrayList<car::Model>::findByID(int id)
{
    for (int i = 0; i < this->_size; i++)
    {
        if (this->_arr[i].id == id)
            return this->_arr[i];
    }

    throw "car not found";
}

// findByMake stores the found cars in the given foundCars parameter and returns the size.
template <>
car::Model *ArrayList<car::Model>::findByMake(std::string make, int &size)
{
    car::Model *temp = new (std::nothrow) car::Model[this->_size];
    if (!temp)
    {
        throw "unable to allocate dynamic memory for temp array";
    }

    size = 0;
    for (int i = 0; i < this->_size; i++)
    {
        if (this->_arr[i].make == make)
        {
            temp[size] = this->_arr[i];
            size++;
        }
    }

    car::Model *foundCars = new (std::nothrow) car::Model[size];
    if (!foundCars)
    {
        throw "unable to allocate dynamic memory for returned array";
    }

    for (int i = 0; i < size; i++)
    {
        foundCars[i] = temp[i];
    }

    return foundCars;
}

template <>
car::Model *ArrayList<car::Model>::findByModel(std::string model, int &size)
{
    car::Model *temp = new (std::nothrow) car::Model[this->_size];
    if (!temp)
    {
        throw "unable to allocate dynamic memory for temp array";
    }

    size = 0;
    for (int i = 0; i < this->_size; i++)
    {
        if (this->_arr[i].model == model)
        {
            temp[size] = this->_arr[i];
            size++;
        }
    }

    car::Model *foundCars = new (std::nothrow) car::Model[size];
    if (!foundCars)
    {
        throw "unable to allocate dynamic memory for returned array";
    }

    for (int i = 0; i < size; i++)
    {
        foundCars[i] = temp[i];
    }

    return foundCars;
}

template <>
car::Model *ArrayList<car::Model>::findByColor(std::string color, int &size)
{
    car::Model *temp = new (std::nothrow) car::Model[this->_size];
    if (!temp)
    {
        throw "unable to allocate dynamic memory for temp array";
    }

    size = 0;
    for (int i = 0; i < this->_size; i++)
    {
        if (this->_arr[i].color == color)
        {
            temp[size] = this->_arr[i];
            size++;
        }
    }

    car::Model *foundCars = new (std::nothrow) car::Model[size];
    if (!foundCars)
    {
        throw "unable to allocate dynamic memory for returned array";
    }

    for (int i = 0; i < size; i++)
    {
        foundCars[i] = temp[i];
    }

    return foundCars;
}

template <>
void ArrayList<car::Model>::delByID(int id)
{
    for (int i = 0; i < this->_size; i++)
    {
        if (this->_arr[i].id == id)
        {
            this->del(i);
            return;
        }
    }

    throw "id not found";
}

template class ArrayList<car::Model>;
