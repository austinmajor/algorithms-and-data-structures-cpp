// 20191023_queue_implementation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>
#include <queue>
#include <stack>

template <class T>
class StackQueue {
private: 
	std::stack<T> s1;
	std::stack<T> s2;

public: 
	StackQueue() {}
	void enqueue(T data) { s1.push(data); }
	T dequeue() {
		if (s2.empty()) {
			while (!s1.empty()) {
				T temp = s1.top();
				s2.push(temp);
				s1.pop();
			}
		}

		T temp = s2.top();
		s2.pop();
		return temp; 
	}

	bool isFull() { return false; }
	bool isEmpty() {
		return s1.empty() && s2.empty();
	}
};

int main() {
	StackQueue<int> q;

	for (int i = 0; i < 5; ++i)
		q.enqueue(i * 11);

	while (!q.isEmpty()) {
		std::cout << q.dequeue() << std::endl;
	}

	return 0; 
}