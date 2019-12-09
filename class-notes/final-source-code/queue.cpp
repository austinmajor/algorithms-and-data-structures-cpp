// 20191021_queue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class MyQueue{
private: 
	int a[5];
	int tail;
	int head; 

public: 
	MyQueue() :tail(0), head(0) {}

	void enqueue(int num);
	int dequeue();
	bool isFull();
	bool isEmpty();
};

void MyQueue::enqueue(int num) {
	if (isFull()) {
		std::cerr << "Cannot enequeue. Queue is full. \n";
		exit(1);
	}
	
	a[tail] = num;
	tail = (tail + 1) % 5;
}

int MyQueue::dequeue() {
	if (isEmpty()) {
		std::cerr << "Cannot dequeue. Queue is empty. \n";
		exit(1);
	}

	int temp = a[head];
	head = (head + 1) % 5;

	return temp; 
}

bool MyQueue::isEmpty() {
	return head == tail; 
}

bool MyQueue::isFull() {
	return (tail + 1) % 5 == head; 
}

int main()
{
	using namespace std; 
	MyQueue q;

	q.enqueue(1);
	q.enqueue(1);
	q.enqueue(1);
	q.enqueue(1);

	cout << "ch 1" << q.isFull();

	q.dequeue();
	q.dequeue();

	cout <<"ch 2" <<q.isFull();

	q.enqueue(2);

	cout << "ch 3" << q.isFull();


	return 0;
}