#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <string>

class ArrayList
{
	private:
		int *_arr;
		int _capacity;
		int _size;

		bool _isFull();
		void _increaseCapacity();
	public:
		ArrayList();
		ArrayList(int);
		ArrayList(const ArrayList&);
		ArrayList& operator=(const ArrayList&);
		~ArrayList();

		int size();
		int capacity();

		void add(int);
		void add(int, int);
		void set(int, int);
		void push_back(int);
		int pop();
		int get(int);
		void del(int);

		std::string print();
};

#endif
