#include "../include/ReportManager.h"

#include <iostream>
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

    cout << fixed << setprecision(2);

    cout << "\n====================================\n";
    cout << "          EXPENSE REPORT\n";
    cout << "====================================\n";

    cout << "Fuel expenses:      "
         << fuelCost << endl;

    cout << "Repair expenses:    "
         << repairCost << endl;

    cout << "------------------------------------\n";

    cout << "Total expenses:     "
         << total << endl;

    cout << "\n";

    vector<FuelRecord> fuels =
        fuelManager.getRecords();

    vector<RepairRecord> repairs =
        repairManager.getRecords();

    double averageFuel = 0;

    if(!fuels.empty())
    {
        averageFuel =
            fuelCost / fuels.size();
    }

    cout << "Average fuel cost: "
         << averageFuel
         << endl;

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

    cout << "Current mileage: "
         << maxMileage
         << " km\n";

    if(maxMileage > 0)
    {
        cout
            << "Cost per km: "
            << total / maxMileage
            << endl;
    }

    cout << "\n";

    map<string,double> categories;

    for(const auto& repair : repairs)
    {
        categories[repair.category]
            += repair.cost;
    }

    cout << "===== REPAIR CATEGORIES =====\n";

    if(categories.empty())
    {
        cout << "No repair records.\n";
    }
    else
    {
        for(const auto& item : categories)
        {
            cout
                << item.first
                << " : "
                << item.second
                << endl;
        }
    }

    cout << "\n";

    if(!repairs.empty())
    {
        RepairRecord expensive =
            repairManager.getMostExpensiveRepair();

        cout << "===== MOST EXPENSIVE REPAIR =====\n";

        cout << "Date: "
             << expensive.date
             << endl;

        cout << "Category: "
             << expensive.category
             << endl;

        cout << "Mileage: "
             << expensive.mileage
             << " km\n";

        cout << "Cost: "
             << expensive.cost
             << endl;
    }

    cout << "\n====================================\n";
}
