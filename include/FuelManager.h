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
    void addFuel();
    void showFuels() const;

    void saveToFile(const string& filename) const;
    void loadFromFile(const string& filename);

    double getTotalFuelCost() const;

    int getRecordCount() const;

    vector<FuelRecord> getRecords() const;
};

#endif
