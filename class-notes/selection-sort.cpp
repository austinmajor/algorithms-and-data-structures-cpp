// 20190821_selection_sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

void selection_sort(int a[], std::size_t size);

int binary_search(int a[], int size, int target, int low, int high);


int main()
{
	int a[] = { 5, 8, 1, 3, 2, 7, 11, 12, 21, 23, 33, 500 };
	std::size_t size = sizeof(a) / sizeof(int);
	selection_sort(a, size);
	for (auto n : a) {
		std::cout << n << " ";
	}
	std::cout << std::endl;

	std::cout << binary_search(a, size, 2, 0, size - 1) << std::endl;
	std::cout << binary_search(a, size, 22, 0, size - 1) << std::endl;
	std::cout << binary_search(a, size, 33, 0, size - 1) << std::endl;


	return 0;
}

void selection_sort(int a[], std::size_t size) {
	for (std::size_t i = 1; i < size; ++i)
		for (std::size_t j = i; j > 0 && a[j] < a[j - 1]; --j)
			std::swap(a[j], a[j - 1]);
}

int binary_search(int a[], int size, int target, int low, int high) {
	while (low <= high) {
		int mid = (low + high) / 2;
		if (a[mid] == target)
			return mid;
		else if (a[mid] < target)
			low = mid + 1;
		else
			high = mid - 1; 
	}

	return -1; 
}
