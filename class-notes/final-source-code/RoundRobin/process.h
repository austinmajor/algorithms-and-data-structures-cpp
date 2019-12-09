#ifndef PROCESS_H
#define PROCESS_H

#include <string>

class Process {
	public:
		Process(int, int, int);
		std::string dump();
		int execute(int, int);
		bool done();
		int arrival();

	private:
		Process();
		int _id, _arrival, _timeRequired, _timeLeft, _timeFinished;
};

#endif
