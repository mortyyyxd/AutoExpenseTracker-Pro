```cpp
#include "../include/FuelManager.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>

using namespace std;

void FuelManager::addFuel()
{
    FuelRecord fuel;

    cout << "\n=== ADD FUEL ===\n";

    cout << "Date: ";
    cin >> fuel.date;

    cout << "Mileage (km): ";
    cin >> fuel.mileage;

    cout << "Liters: ";
    cin >> fuel.liters;

    cout << "Price per liter: ";
    cin >> fuel.pricePerLiter;

    fuels.push_back(fuel);

    cout << "\nFuel added successfully.\n";
}

void FuelManager::showFuels() const
{
    cout << "\n=========== FUEL RECORDS ===========\n";

    if (fuels.empty())
    {
        cout << "No records.\n";
        return;
    }

    cout << fixed << setprecision(2);

    for (size_t i = 0; i < fuels.size(); i++)
    {
        cout
            << i + 1
            << ". Date: " << fuels[i].date
            << " | Mileage: " << fuels[i].mileage
            << " km | Liters: " << fuels[i].liters
            << " | Price: " << fuels[i].pricePerLiter
            << " | Total: " << fuels[i].getTotalCost()
            << endl;
    }
}

double FuelManager::getTotalFuelCost() const
{
    double total = 0;

    for (const auto& fuel : fuels)
    {
        total += fuel.getTotalCost();
    }

    return total;
}

void FuelManager::saveToFile(const string& filename) const
{
    ofstream file(filename);

    if (!file.is_open())
        return;

    for (const auto& fuel : fuels)
    {
        file
            << fuel.date << ";"
            << fuel.mileage << ";"
            << fuel.liters << ";"
            << fuel.pricePerLiter
            << endl;
    }

    file.close();
}

void FuelManager::loadFromFile(const string& filename)
{
    ifstream file(filename);

    if (!file.is_open())
        return;

    fuels.clear();

    FuelRecord fuel;
    char separator;

    while (
        getline(file, fuel.date, ';') &&
        file >> fuel.mileage >> separator &&
        file >> fuel.liters >> separator &&
        file >> fuel.pricePerLiter
    )
    {
        file.ignore();

        fuels.push_back(fuel);
    }

    file.close();
}

int FuelManager::getRecordCount() const
{
    return fuels.size();
}

vector<FuelRecord> FuelManager::getRecords() const
{
    return fuels;
}

void FuelManager::deleteFuel()
{
    if (fuels.empty())
    {
        cout << "No records.\n";
        return;
    }

    showFuels();

    int index;

    cout << "\nRecord number to delete: ";
    cin >> index;

    if (index < 1 || index > (int)fuels.size())
    {
        cout << "Invalid index.\n";
        return;
    }

    fuels.erase(fuels.begin() + index - 1);

    cout << "Deleted successfully.\n";
}

void FuelManager::editFuel()
{
    if (fuels.empty())
    {
        cout << "No records.\n";
        return;
    }

    showFuels();

    int index;

    cout << "\nRecord number to edit: ";
    cin >> index;

    if (index < 1 || index > (int)fuels.size())
    {
        cout << "Invalid index.\n";
        return;
    }

    FuelRecord& fuel = fuels[index - 1];

    cout << "New date: ";
    cin >> fuel.date;

    cout << "New mileage: ";
    cin >> fuel.mileage;

    cout << "New liters: ";
    cin >> fuel.liters;

    cout << "New price: ";
    cin >> fuel.pricePerLiter;

    cout << "Updated successfully.\n";
}

void FuelManager::searchByDate(const string& date) const
{
    bool found = false;

    for (const auto& fuel : fuels)
    {
        if (fuel.date == date)
        {
            found = true;

            cout
                << fuel.date
                << " | "
                << fuel.mileage
                << " km | "
                << fuel.getTotalCost()
                << endl;
        }
    }

    if (!found)
    {
        cout << "Nothing found.\n";
    }
}

void FuelManager::sortByMileage()
{
    sort(
        fuels.begin(),
        fuels.end(),
        [](const FuelRecord& a, const FuelRecord& b)
        {
            return a.mileage < b.mileage;
        }
    );

    cout << "Sorted by mileage.\n";
}

void FuelManager::sortByCost()
{
    sort(
        fuels.begin(),
        fuels.end(),
        [](const FuelRecord& a, const FuelRecord& b)
        {
            return a.getTotalCost() < b.getTotalCost();
        }
    );

    cout << "Sorted by cost.\n";
}

FuelRecord FuelManager::getMostExpensiveFuel() const
{
    FuelRecord result{};

    if (fuels.empty())
        return result;

    result = fuels[0];

    for (const auto& fuel : fuels)
    {
        if (fuel.getTotalCost() > result.getTotalCost())
        {
            result = fuel;
        }
    }

    return result;
}

FuelRecord FuelManager::getCheapestFuel() const
{
    FuelRecord result{};

    if (fuels.empty())
        return result;

    result = fuels[0];

    for (const auto& fuel : fuels)
    {
        if (fuel.getTotalCost() < result.getTotalCost())
        {
            result = fuel;
        }
    }

    return result;
}
```

