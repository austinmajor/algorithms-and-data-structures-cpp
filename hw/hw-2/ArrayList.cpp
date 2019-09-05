#include "ArrayList.h"
#include <iostream>

ArrayList::ArrayList() {
	_pa = new int[10];
	_size = 0;
	_capacity = 10;
}

ArrayList::ArrayList(int capacity) {
	if (capacity > 0) {
		_pa = new int[capacity];
		_size = 0;
		_capacity = capacity;
	}
	else {
		ArrayList();
	}
}

ArrayList::ArrayList(const ArrayList& that) {
	this->_capacity = that._capacity;
	this->_size = that._size;
	// this->_pa = that._pa;	// shallow copy

	this->_pa = new int[_capacity];

	for (int i = 0; i < _size; ++i) {
		this->_pa[i] = that._pa[i];
	}
}

ArrayList& ArrayList::operator=(const ArrayList& that) {
	if (this != &that){
		int* temp = _pa;

		this->_capacity = that._capacity;
		this->_size = that._size;
		this->_pa = new int[_capacity];
		for (int i = 0; i < _size; ++i) {
			this->_pa[i] = that._pa[i];
		}

		delete[] temp;
	}

	return *this;
}

ArrayList::~ArrayList() {
	delete[] _pa;
}

void ArrayList::push_back(int num) {
	add(num);
}

int ArrayList::pop() {
	if (_size <= 0) {
		std::cerr << "Fail to exec pop(). ArrayList empty.";
		exit(1);
	}

	int temp = _pa[_size - 1];
	_size--;
	return temp;
}

// O is constant
int ArrayList::get(int index) {
	if (index < 0 || index >= _size) {
		std::cerr << "Fail to exec get(). Invalid index.";
		exit(1);
	}

	return _pa[index];
}

// O is constant
void ArrayList::set(int index, int num) {
	if (index < 0 || index >= _size) {
		std::cerr << "Fail to exec set(). Invalid index.";
		exit(1);
	}

	_pa[index] = num;

}

// O(n)
void ArrayList::add(int index, int num) {

	// invalid index, call exit()
	if (index < 0 || index > _size) {
		std::cerr << "Invalid index. " << std::endl;
		exit(1);
	}

	// valid index, add new element
	if (!_isFull()) {
		// case 1: add and shift
		// case 2: add without shifting

		// shift 0 or more elements
		for (int i = _size - 1; i >= index; --i) {		// note that (_size - 1)
			_pa[i + 1] = _pa[i];
		}

		// set new element
		_pa[index] = num;

		// manage _size
		_size++;

	}
	else {
		_doubleCapacity();
		add(index, num);
	}
}

// O(1)
void ArrayList::add(int num) {

	if (!_isFull()) {
		_pa[_size] = num;

		// manage _size
		_size++;
	}
	else {
		_doubleCapacity();
		add(num);
	}
}

void ArrayList::del(int index) {
	// TO_DO: implement this function

}

int ArrayList::size() {
	return _size;
}

int ArrayList::capacity() {
	return _capacity;
}

void ArrayList::traverse() {
	for (int i = 0; i < _size; ++i) {
		std::cout << _pa[i] << " ";
	}
	std::cout << std::endl;
}

bool ArrayList::_isFull() {
	return _size == _capacity;
}

void ArrayList::_doubleCapacity() {
	// allocate new space with doubled capacity
	int* temp = new int[_capacity * 2];

	// copy existing elements over
	for (int i = 0; i < _size; ++i) {
		temp[i] = _pa[i];
	}

	// update _capacity
	_capacity *= 2;

	// update _pa
	delete[] _pa;
	_pa = temp;
}
