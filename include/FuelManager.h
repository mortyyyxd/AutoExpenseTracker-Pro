#ifndef FUEL_MANAGER_H
#define FUEL_MANAGER_H

#include <string>
#include <vector>

using namespace std;

struct FuelRecord
{
    string date;
    int mileage;
    double liters;
    double pricePerLiter;

    double getTotalCost() const
    {
        return liters * pricePerLiter;
    }
};

class FuelManager
{
private:
    vector<FuelRecord> fuels;

public:
    // Основні функції
    void addFuel();
    void showFuels() const;

    // Робота з файлами
    void saveToFile(const string& filename) const;
    void loadFromFile(const string& filename);

    // Статистика
    double getTotalFuelCost() const;

    int getRecordCount() const;

    vector<FuelRecord> getRecords() const;

    // Нові можливості
    void editFuel();
    void deleteFuel();

    void searchByDate(const string& date) const;

    void sortByMileage();
    void sortByCost();

    FuelRecord getMostExpensiveFuel() const;
    FuelRecord getCheapestFuel() const;
};

#endif
