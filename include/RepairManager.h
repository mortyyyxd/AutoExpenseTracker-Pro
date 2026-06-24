#ifndef REPAIR_MANAGER_H
#define REPAIR_MANAGER_H

#include <string>
#include <vector>

using namespace std;

struct RepairRecord
{
    string date;
    int mileage;
    string category;
    double cost;
};

class RepairManager
{
private:
    vector<RepairRecord> repairs;

public:
    void addRepair();
    void showRepairs() const;

    void saveToFile(const string& filename) const;
    void loadFromFile(const string& filename);

    double getTotalRepairCost() const;

    RepairRecord getMostExpensiveRepair() const;

    vector<RepairRecord> getRecords() const;

    int getRecordCount() const;
};

void editFuel();
void deleteFuel();

void searchByDate(const string& date) const;

void sortByMileage();
void sortByCost();

FuelRecord getMostExpensiveFuel() const;
FuelRecord getCheapestFuel() const;

#endif
