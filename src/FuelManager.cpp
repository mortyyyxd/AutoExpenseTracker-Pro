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
