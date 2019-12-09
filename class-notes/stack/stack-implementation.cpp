// 20190918_stack_implementation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>


template <class T>
class Stack {
private: 
	T arr[30];
	int top; 
public: 
	Stack() : top(0) {}
	// push pop, peek, size, isFull , isEmpty 
	void push(T ele) {
		if (!isFull()) {
			arr[top++] = ele;
		}
	}

	T pop() {
		if (isEmpty()) {
			exit(1);
		}
		--top;
		return arr[top];
	}

	T peek() {
		if (isEmpty()) {
			exit(1);
		}
		return arr[top - 1];
	}
	int size() { return top; }
	bool isEmpty() { return top == 0; }
	bool isFull() { return top == 30; }
};

void checkBalance() {
	using namespace std;
	Stack<char> st1;
	string str = "(()))";

	// for(int i =0; i < str.length(); ++i)
	for (auto ch : str) {
		if (ch == '(') {
			st1.push('(');
		}
		else {
			if (st1.isEmpty()) {
				cout << "NOT balanced. " << endl;
				return ;
			}
			st1.pop();
		}
	}
	if (st1.isEmpty()) {
		cout << "Balanced. " << endl;
	}
	else {
		cout << "NOT balanced. " << endl;
	}
}

int main()
{
	checkBalance();


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file