#include <sstream>

#include "process.h"

Process::Process(int id, int arrival, int timeRequired) :
	_id(id), _arrival(arrival), _timeRequired(timeRequired),
	_timeLeft(timeRequired), _timeFinished(-1) {}

std::string Process::dump() {
	std::stringstream ss;

	ss << this->_id << "\t" << this->_arrival << "\t\t" << this->_timeRequired
		<< "\t\t" << this->_timeFinished;

	return ss.str();
}

int Process::execute(int time, int elapsed) {
	int executionTime = time;

	if(time >= this->_timeLeft) {
		executionTime = this->_timeLeft;
		
		this->_timeFinished = elapsed + this->_timeLeft;
		this->_timeLeft = 0;
	} else {
		this->_timeLeft -= time;
	}

	return executionTime;
}

bool Process::done() {
	return this->_timeLeft == 0;
}

int Process::arrival() {
	return this->_arrival;
}
