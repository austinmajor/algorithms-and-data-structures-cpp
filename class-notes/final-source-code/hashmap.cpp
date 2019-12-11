// 20191113_hashmap.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <unordered_map>

int main()
{
	// create and init
	std::unordered_map<int, int> umap = { {1, 1111}, {2, 223234}, {3, 321}, {4, 4678} };

	// add new (key, value)
	umap[5] = 5;
	umap[5] = 54321;

	// erase
	umap.erase(5);

	// search
	if (umap.find(5) != umap.end())
		std::cout << "key 5 found in umap. " << "its value: " << umap[5] << std::endl;
	else
		std::cout << "could not find key 5. \n";

	// iterate
	for (auto i : umap)
		std::cout << i.first << ": " << i.second << std::endl;

	for (std::unordered_map<int, int>::const_iterator i = umap.begin(); i != umap.end(); ++i)
		std::cout << i->first << ": " << i->second << std::endl;


	// hash function

	// function pointer
	auto hash_func = umap.hash_function();

	for (int i = 1; i < 5; ++i)
		std::cout << "hash value of " << i << ": " << hash_func(i) << std::endl;

}
