// 20190916_stack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
#include "ArrayList.h"

class Stack {
private:
	ArrayList list;
public: 
	void push(int num) { list.push_back(num); }
	int pop() { return list.pop(); }
	int top() { return list.get(list.size() - 1); }
	bool isFull() { return list.size() == list.capacity(); }
	bool isEmpty() { return list.size() <= 0; }
};



int main()
{
	int num = 48;
	Stack st;

	std::stack<int> sta;

	while (num != 0) {
		st.push(num % 2);
		num /= 2;
	}

	while (!st.isEmpty())
	{
		std::cout << st.pop();
	}

	return 0;
}