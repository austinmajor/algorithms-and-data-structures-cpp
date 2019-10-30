#include <iostream>

void permutate(std::string set, int lowerbound, int upperbound) {
	if(lowerbound == upperbound) {
		std::cout << set << std::endl;
		return;
	}

	for(int i = lowerbound; i <= upperbound; i++) {
		std::swap(set[lowerbound], set[upperbound]);
		permutate(set, lowerbound + 1, upperbound);
		std::swap(set[lowerbound], set[upperbound]);
	}
}

int main() {
	std::string set = "12345";
	permutate(set, 0, set.size() - 1);
	return 0;
}
