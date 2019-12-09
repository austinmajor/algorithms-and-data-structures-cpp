#include <iostream>
#include <queue>
#include <fstream>
#include <vector>

#include "process.h"

int main() {
	const int timeframe = 4;

	std::queue<Process> q;
	std::vector<Process> done;

	std::ifstream f("round_robin.txt");
	if(!f.is_open()) {
		std::cout << "unable to open input file" << std::endl;
	}

	int id, arrival, timeRequired;
	while(f >> id >> arrival >> timeRequired) {
		q.push(Process(id, arrival, timeRequired));
	}
	f.close();

	int elapsedTime = q.front().arrival();
	while(!q.empty()) {
		elapsedTime += q.front().execute(timeframe, elapsedTime);
		
		if(q.front().done()) {
			done.push_back(q.front());
			q.pop();
			continue;
		}

		q.push(q.front());
		q.pop();
	}

	std::cout << "ID\tArrival Time\tTime Required\tTime Spent\n";
	for(Process p : done) {
		std::cout << p.dump() << std::endl;
	}

	return 0;
}
