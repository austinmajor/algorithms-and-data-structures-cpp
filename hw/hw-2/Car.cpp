#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdio>

#include "ArrayList.h"
#include "Car.h"

namespace car
{
// ParseDataFile parses an entire .data file for cars.
ArrayList<Model> ParseDataFile(std::string file)
{
    ArrayList<Model> cars;
    std::string line;
    std::ifstream data(file);

    if (data.is_open())
    {
        while (std::getline(data, line))
        {
            cars.push_back(ParseDataRow(line));
        }
        data.close();
    }
    else
    {
        throw "unable to open file";
    }

    return cars;
}

// ParseDataRow parses a singular row in a given .data file for Cars.
Model ParseDataRow(std::string line)
{
    Model car;
    std::stringstream ss(line);
    std::string column;

    int columnCount = 0;
    while (std::getline(ss, column, ','))
    {
        switch (columnCount)
        {
        case 0:
            car.id = std::stoi(column);
            break;
        case 1:
            car.make = column;
            break;
        case 2:
            car.model = column;
            break;
        case 3:
            car.color = column;
            break;
        default:
            throw "line in data file misformatted";
        }

        columnCount++;
    }

    return car;
}

// PrintModel prints all of the metadata regarding a Model.
std::string PrintModel(Model m)
{
    std::stringstream ss;

    ss << m.id << "," << m.make << "," << m.model << "," << m.color;

    return ss.str();
}

// AddModel adds a model to a given data file.
void AddModel(std::string file, Model newCar)
{
    std::ofstream data(file, std::ios_base::app);

    if (data.is_open())
    {
        data << PrintModel(newCar) << std::endl;
        data.close();
    }
    else
    {
        throw "unable to open file";
    }
}

// DeleteModel deletes a given model by ID in a given data file.
void DeleteModel(std::string file, int id)
{
    std::ifstream data(file);
    std::ofstream temp("temp.data");

    std::string line;

    if (data.is_open() && temp.is_open())
    {
        while (std::getline(data, line))
        {
            if (ParseDataRow(line).id != id)
            {
                temp << line << std::endl;
            }
        }

        data.close();
        temp.close();
    }

    std::remove(file.c_str());
    std::rename("temp.data", file.c_str());
}
}; // namespace car
