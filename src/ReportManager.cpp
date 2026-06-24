```cpp
#include "../include/ReportManager.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <map>

using namespace std;

void ReportManager::showFullReport(
    const FuelManager& fuelManager,
    const RepairManager& repairManager
)
{
    double fuelCost =
        fuelManager.getTotalFuelCost();

    double repairCost =
        repairManager.getTotalRepairCost();

    double total =
        fuelCost + repairCost;

    vector<FuelRecord> fuels =
        fuelManager.getRecords();

    vector<RepairRecord> repairs =
        repairManager.getRecords();

    cout << fixed << setprecision(2);

    cout << "\n====================================\n";
    cout << "         VEHICLE REPORT\n";
    cout << "====================================\n";

    cout << "Fuel expenses:      "
         << fuelCost << endl;

    cout << "Repair expenses:    "
         << repairCost << endl;

    cout << "Total expenses:     "
         << total << endl;

    double averageFuel = 0;

    if(!fuels.empty())
        averageFuel = fuelCost / fuels.size();

    cout << "\nAverage fuel expense: "
         << averageFuel << endl;

    double averageRepair = 0;

    if(!repairs.empty())
        averageRepair = repairCost / repairs.size();

    cout << "Average repair expense: "
         << averageRepair << endl;

    int maxMileage = 0;

    for(const auto& fuel : fuels)
    {
        if(fuel.mileage > maxMileage)
            maxMileage = fuel.mileage;
    }

    for(const auto& repair : repairs)
    {
        if(repair.mileage > maxMileage)
            maxMileage = repair.mileage;
    }

    cout << "\nCurrent mileage: "
         << maxMileage
         << " km\n";

    if(maxMileage > 0)
    {
        cout << "Cost per km: "
             << total / maxMileage
             << endl;

        cout << "Cost per 100 km: "
             << (total / maxMileage) * 100
             << endl;
    }

    cout << "\n===== REPAIR CATEGORIES =====\n";

    map<string,double> categories;

    for(const auto& repair : repairs)
    {
        categories[repair.category]
            += repair.cost;
    }

    for(const auto& item : categories)
    {
        cout
            << item.first
            << " : "
            << item.second
            << endl;
    }

    if(!fuels.empty())
    {
        FuelRecord expensiveFuel =
            fuelManager.getMostExpensiveFuel();

        FuelRecord cheapFuel =
            fuelManager.getCheapestFuel();

        cout << "\n===== FUEL ANALYSIS =====\n";

        cout << "Most expensive fuel: "
             << expensiveFuel.getTotalCost()
             << endl;

        cout << "Cheapest fuel: "
             << cheapFuel.getTotalCost()
             << endl;
    }

    if(!repairs.empty())
    {
        RepairRecord repair =
            repairManager.getMostExpensiveRepair();

        cout << "\n===== MOST EXPENSIVE REPAIR =====\n";

        cout << "Date: "
             << repair.date << endl;

        cout << "Category: "
             << repair.category << endl;

        cout << "Cost: "
             << repair.cost << endl;
    }

    cout << "\n====================================\n";
}

void ReportManager::exportReportToFile(
    const FuelManager& fuelManager,
    const RepairManager& repairManager,
    const string& filename
)
{
    ofstream file(filename);

    if(!file.is_open())
    {
        cout << "Cannot create report.\n";
        return;
    }

    double fuelCost =
        fuelManager.getTotalFuelCost();

    double repairCost =
        repairManager.getTotalRepairCost();

    double total =
        fuelCost + repairCost;

    file << "CAR EXPENSE REPORT\n";
    file << "===========================\n";

    file << "Fuel expenses: "
         << fuelCost
         << endl;

    file << "Repair expenses: "
         << repairCost
         << endl;

    file << "Total expenses: "
         << total
         << endl;

    file.close();

    cout << "Report exported to "
         << filename
         << endl;
}
```
