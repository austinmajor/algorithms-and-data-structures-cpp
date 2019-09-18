#pragma once

#ifndef ARRAYLIST_H
#define ARRAYLIST_H

class ArrayList
{
public:
    ArrayList();
    ArrayList(int capacity);
    ArrayList(const ArrayList &that);
    ArrayList &operator=(const ArrayList &that);
    ~ArrayList();

    // interface
    void push_back(int num);
    int pop();
    int get(int index);
    void set(int index, int num);
    void add(int num);
    void add(int index, int num);
    void del(int index);
    int size();
    int capacity();

    void traverse();

private:
    int *_pa;      // pointer of dynamic array's address
    int _size;     // number of elements used. 1-based.
    int _capacity; // capcacity of the list

    bool _isFull();
    void _doubleCapacity();
};

#endif
