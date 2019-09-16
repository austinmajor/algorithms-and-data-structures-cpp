#ifndef CAR_H
#define CAR_H

#include <string>

#include "ArrayList.h"

namespace car {
	struct Model {
		int id;
		std::string make;
		std::string model;
		std::string color;
	};

	ArrayList<Model> ParseDataFile(std::string);
	Model ParseDataRow(std::string);
	std::string PrintModel(Model);
	void AddModel(std::string, Model);
	void DeleteModel(std::string, int);
};

#endif
