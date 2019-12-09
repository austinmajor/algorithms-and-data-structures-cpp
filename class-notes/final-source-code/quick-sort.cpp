// quick_sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using std::cout;
using std::endl;

void quick(int[], int, int);
int partition(int[], int p, int);
void swap(int&, int&);
void print(int[], int);

int main()
{
	
	int a[] = { 4, 5, 3, 2, 20, 9, 99, 0, 11};
	int size = sizeof(a) / sizeof(int);
	print(a, size);
	quick(a, 0, size - 1);	// NOT size: since the last valid index is size-1 
	print(a, size);

	return 0;
}

void quick(int a[], int p, int r) {
	if (p < r) {
		int q = partition(a, p, r);
		quick(a, p, q - 1);
		quick(a, q + 1, r);
	}
}

int partition(int a[], int p, int r) {
	int x = a[r];
	int i = p - 1;
	for (int j = p; j < r; ++j) {
		if (a[j] <= x){
			++i;
			swap(a[i], a[j]);
		}
	}
	swap(a[i + 1], a[r]);
	return i + 1;
}

void swap(int& x, int& y) {
	int t = x;
	x = y;
	y = t;
}

void print(int a[], int size) {
	for (int i = 0; i < size; ++i) {
		cout << a[i] << " "; 
	}
	cout << endl;
}