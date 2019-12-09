// 20190923_stack_LL_implementation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>
#include <string>

template <class T>
class Stack {
private: 
	std::list<T> li;
public:
	Stack() {}
	
	bool isEmpty() { return li.size() == 0; }
	bool isFull() { return false; }

	void push(T data) { li.push_front(data); }
	T pop() {
		if (isEmpty()) {
			exit(1);
		}

		T temp = li.front();
		li.pop_front();
		return temp;
	}

	T peek() {
		if (isEmpty()) {
			exit(1);
		}
		return li.front();
	}
};



int main()
{
	Stack<int> st; 

	std::cout << st.isEmpty() << std::endl;

	st.push(10);
	st.push(20);

	std::cout << st.peek() << std::endl;
	st.pop();
	std::cout << st.peek() << std::endl;




}