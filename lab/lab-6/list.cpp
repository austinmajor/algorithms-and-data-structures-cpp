#include <iostream>
#include <list>
using namespace std;

// Queue implementation in C++ using std::list
int main()
{
	list<string> q;

	q.push_back("A");	// Insert "A" in the queue
	q.push_back("B");	// Insert "B" in the queue
	q.push_back("C");	// Insert "C" in the queue
	q.push_back("D");	// Insert "D" in the queue

	// Returns the number of elements present in the queue
	cout << "Queue size is " << q.size() << endl;

	// Prints the front of the queue ("A")
	cout << "Front element is: " << q.front() << endl;

	// Prints the rear of the queue ("D")
	cout << "Rear element is: " << q.back() << endl;

	q.pop_front();	// removing the front element ("A")
	q.pop_front();	// removing the next front element ("B")

	cout << "Queue size is " << q.size() << endl;

	// check if queue is empty
	if (q.empty())
		cout << "Queue is Empty\n";
	else
		cout << "Queue is not Empty\n";

	return 0;
}