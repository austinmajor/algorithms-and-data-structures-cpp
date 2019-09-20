#include <iostream>
#include <string>
#include <sstream>

#include "ArrayList.h"
#include "Car.h"

// Forward function declarations, for specific function comments see their
// implementations after main.
std::string menu();

int main()
{
    std::string dataFile;
    ArrayList<car::Model> cars;

    std::cout << "Enter the name of your data file (with extension): ";
    std::cin >> dataFile;

    try
    {
        cars = car::ParseDataFile(dataFile);
    }
    catch (const char *e)
    {
        std::cerr << "error: " << e << std::endl;
        return 1;
    }

    // Formatting after opening file.
    std::cout << std::endl;

    bool running = true;
    std::string selection;
    int parsedSelection;

    while (running)
    {
        std::cout << menu();
        std::cin >> selection;

        try
        {
            parsedSelection = std::stoi(selection);
        }
        catch (...)
        {
            std::cout << "Invalid selection, try again." << std::endl
                      << std::endl;
            continue;
        }

        switch (parsedSelection)
        {
        case 1:
        {
            std::cout << std::endl
                      << cars.print() << std::endl;
            break;
        }
        case 2:
        {
            std::cout << std::endl
                      << "Enter an ID to search by: ";
            std::cin >> selection;

            try
            {
                parsedSelection = std::stoi(selection);
            }
            catch (...)
            {
                std::cout << "Invalid ID given, returning to menu."
                          << std::endl
                          << std::endl;
                continue;
            }

            try
            {
                std::cout << car::PrintModel(cars.findByID(parsedSelection))
                          << std::endl
                          << std::endl;
            }
            catch (const char *e)
            {
                std::cout << "Error finding car by ID: " << e
                          << std::endl
                          << std::endl;
            }
            break;
        }
        case 3:
        {
            std::cout << std::endl
                      << "Enter a make to search by: ";
            std::cin >> selection;

            int size = 0;
            car::Model *foundCars = cars.findByMake(selection, size);

            if (size == 0)
            {
                std::cout << "No cars found by given make, returning to menu." << std::endl
                          << std::endl;
                continue;
            }

            for (int i = 0; i < size; i++)
            {
                std::cout << car::PrintModel(foundCars[i]) << std::endl;
            }

            // Formatting
            std::cout << std::endl;

            break;
        }
        case 4:
        {
            std::cout << std::endl
                      << "Enter a model to search by: ";
            std::cin >> selection;

            int size = 0;
            car::Model *foundCars = cars.findByModel(selection, size);

            if (size == 0)
            {
                std::cout << "No cars found by given model, returning to menu." << std::endl
                          << std::endl;
                continue;
            }

            for (int i = 0; i < size; i++)
            {
                std::cout << car::PrintModel(foundCars[i]) << std::endl;
            }

            // Formatting
            std::cout << std::endl;

            break;
        }
        case 5:
        {
            std::cout << std::endl
                      << "Enter a color to search by: ";
            std::cin >> selection;

            int size = 0;
            car::Model *foundCars = cars.findByColor(selection, size);

            if (size == 0)
            {
                std::cout << "No cars found by given color, returning to menu." << std::endl
                          << std::endl;
                continue;
            }

            for (int i = 0; i < size; i++)
            {
                std::cout << car::PrintModel(foundCars[i]) << std::endl;
            }

            // Formatting
            std::cout << std::endl;

            break;
        }
        case 6:
        {
            car::Model newCar;

            // Get new ID by getting the last element's ID and adding one.
            newCar.id = cars.get(cars.size() - 1).id + 1;

            std::cout << std::endl
                      << "Enter the make of the car to add: ";
            std::cin >> newCar.make;

            std::cout << "Enter the model of the car to add: ";
            std::cin >> newCar.model;

            std::cout << "Enter the color of the car to add: ";
            std::cin >> newCar.color;

            try
            {
                car::AddModel(dataFile, newCar);
            }
            catch (const char *e)
            {
                std::cout << "Error encountered adding car: "
                          << e << std::endl
                          << std::endl;
                continue;
            }

            cars.push_back(newCar);

            std::cout << std::endl
                      << "New car succesfully added: "
                      << PrintModel(newCar) << std::endl
                      << std::endl;

            break;
        }
        case 7:
        {
            std::cout << std::endl
                      << "Enter an ID to delete: ";
            std::cin >> selection;

            try
            {
                parsedSelection = std::stoi(selection);
            }
            catch (...)
            {
                std::cout << "Invalid ID given, returning to menu."
                          << std::endl
                          << std::endl;
                continue;
            }

            try
            {
                cars.delByID(parsedSelection);
                car::DeleteModel(dataFile, parsedSelection);
            }
            catch (const char *e)
            {
                std::cout << "Error deleting car by ID: " << e
                          << std::endl
                          << std::endl;
            }

            std::cout << "Car (ID:" << parsedSelection
                      << ") has been succesfully deleted." << std::endl
                      << std::endl;

            break;
        }
        case 8:
        {
            running = false;
            break;
        }
        default:
        {
            std::cout << std::endl
                      << "Invalid selection, try again."
                      << std::endl
                      << std::endl;
            break;
        }
        }
    }

    return 0;
}

// Menu returns the string representation of the menu for the program.
std::string menu()
{
    std::stringstream ss;

    ss << "Menu:" << std::endl
       << "1. List all cars" << std::endl
       << "2. Search by ID"
       << std::endl
       << "3. Search by make" << std::endl
       << "4. Search by model"
       << std::endl
       << "5. Search by color" << std::endl
       << "6. Add new car"
       << std::endl
       << "7. Delete by ID" << std::endl
       << "8. Exit" << std::endl
       << std::endl
       << "Select an operation by its numeric key: ";

    return ss.str();
}
