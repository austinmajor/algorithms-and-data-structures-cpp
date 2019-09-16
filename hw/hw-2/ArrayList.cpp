#include <algorithm>
#include <string>
#include <sstream>

#include "ArrayList.h"

bool ArrayList::_isFull()
{
    if(this->_size >= this->_capacity)
    {
        return true;
    }

    return false;
}

void ArrayList::_increaseCapacity()
{
    this->_capacity = this->_capacity * 2;

    int *temp = new (std::nothrow) int[this->_capacity];
    if(!temp)
    {
        throw "failed to dynamically allocate memory";
    }

    for(int i = 0; i < this->_size; i++)
    {
        temp[i] = this->_arr[i];
    }

    delete[] this->_arr;
    this->_arr = temp;
}

ArrayList::ArrayList() : _capacity(10), _size(0)
{
    this->_arr = new (std::nothrow) int[this->_capacity];
    if(!this->_arr)
    {
        throw "failed to dynamically allocate memory for given size";
    }
}

ArrayList::ArrayList(int capacity) : _capacity(capacity), _size(0)
{
    if(capacity > 0)
    {
        this->_arr = new (std::nothrow) int[this->_capacity];
        if(!this->_arr)
        {
            throw "failed to dynamically allocate memory for given size";
        }

        return;
    }

    // If an invalid capacity was given, use default constructor.
    ArrayList();
}

ArrayList::ArrayList(const ArrayList &that): _capacity(that._capacity), _size(that._size)
{
    this->_arr = new (std::nothrow) int[this->_capacity];
    if(!this->_arr)
    {
        throw "failed to dynamically allocate memory for given size";
    }

    for(int i = 0; i < this->_size; i++)
    {
        this->_arr[i] = that._arr[i];
    }
}

ArrayList& ArrayList::operator=(const ArrayList &that)
{
    if(this != &that)
    {
        this->_capacity = that._capacity;
        this->_size = that._size;

        this->_arr = new (std::nothrow) int[this->_capacity];
        if(!this->_arr)
        {
            throw "failed to dynamically allocate memory";
        }

        for(int i = 0; i < this->_size; i++)
        {
            this->_arr[i] = that._arr[i];
        }
    }

    return *this;
}

ArrayList::~ArrayList()
{
    delete[] this->_arr;
}

int ArrayList::size()
{
    return this->_size;
}

int ArrayList::capacity()
{
    return this->_capacity;
}

void ArrayList::add(int element)
{
    if(this->_isFull()) this->_increaseCapacity();

    this->_arr[this->_size] = element;
    this->_size++;
}

void ArrayList::add(int index, int element)
{
    if(index < 0 || index > this->_size)
    {
        throw "index out of valid range";
    }

    if(this->_isFull()) this->_increaseCapacity();

    // If the element is essentially being added to the end.
    if(index == this->_size)
    {
        this->add(element);
        return;
    }

    // Shift all elements forward from the last element to the desired
    // index.
    for(int i = this->_size - 1; i >= index; i--)
    {
        this->_arr[i + 1] = this->_arr[i];
    }

    // Set the element at the index (nothing is there now) and increment
    // the size.
    this->_arr[index] = element;
    this->_size++;
}

void ArrayList::push_back(int element)
{
    this->add(element);
}

void ArrayList::set(int index, int element)
{
    if(index < 0 || index >= this->_size)
    {
        throw "invalid index given";
    }

    this->_arr[index] = element;
}

int ArrayList::get(int index)
{
    if(index < 0 || index >= this->_size)
    {
        throw "invalid index given";
    }

    return this->_arr[index];
}

void ArrayList::del(int index)
{
    if(index < 0 || index >= this->_size)
    {
        throw "invalid index given";
    }

    int *temp = new (std::nothrow) int[this->_capacity];
    if(!temp)
    {
        throw "unable to allocate memory for dynamic array";
    }

    this->_size--;
    for(int i = index; i < this->_size; i++)
    {
        temp[i] = this->_arr[i + 1];
    }

    delete[] this->_arr;
    this->_arr = temp;
}

int ArrayList::pop()
{
    if(this->_size == 0)
    {
        throw "no elements exist to pop off";
    }


    int *temp = new (std::nothrow) int[this->_capacity];
    if(!temp)
    {
        throw "error allocating memory for dynamic array";
    }

    for(int i = 0; i < this->_size - 1; i++)
    {
        temp[i] = this->_arr[i];
    }

    // Capture popped value to return.
    int popped = this->_arr[this->_size - 1];

    // Delete backing array, replace with new one, and decrement size.
    delete[] this->_arr;
    this->_arr = temp;
    this->_size--;

    return popped;
}

std::string ArrayList::print()
{
    std::stringstream ss;

    for(int i = 0; i < this->_size; i++)
    {
        ss << this->_arr[i] << " ";
    }

    return ss.str();
}
