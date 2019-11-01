#include <iostream>
#include <stack>
#include <cstdlib>
using namespace std;

// Implement Queue using single stack and recursion
class Queue {
	stack<int> s;

public:
	// Enqueue an item to the queue
	void enqueue(int data)
	{
		// Push item into the first stack
		s.push(data);
	}

	// Dequeue an item from the queue
	int dequeue()
	{
		// if stack is empty
		if (s.empty()) {
			cout << "Underflow!!";
			exit(0);
		}

		// pop an item from the stack
		int top = s.top();
		s.pop();

		// if stack becomes empty, return the popped item
		if (s.empty()) {
			return top;
		}

		// recur
		int item = dequeue();

		// push popped item back to the stack
		s.push(top);

		// return the result of dequeue() call
		return item;
	}
};

int main()
{
	int keys[] = { 1, 2, 3, 4, 5 };
	Queue q;

	// insert above keys into the queue
	for (int key : keys) {
		q.enqueue(key);
	}

	cout << q.dequeue() << '\n';	// print 1
	cout << q.dequeue() << '\n';	// print 2

	return 0;
}