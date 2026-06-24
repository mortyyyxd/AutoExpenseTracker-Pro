```cpp
#include "../include/RepairManager.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>

using namespace std;

void RepairManager::addRepair()
{
    RepairRecord repair;

    cout << "\n=== ADD REPAIR ===\n";

    cout << "Date: ";
    cin >> repair.date;

    cout << "Mileage (km): ";
    cin >> repair.mileage;

    cout << "\nCategories:\n";
    cout << "1. Engine\n";
    cout << "2. Suspension\n";
    cout << "3. Brakes\n";
    cout << "4. Electrical\n";
    cout << "5. Tires\n";
    cout << "6. Other\n";

    int choice;

    cout << "Select category: ";
    cin >> choice;

    switch(choice)
    {
        case 1: repair.category = "Engine"; break;
        case 2: repair.category = "Suspension"; break;
        case 3: repair.category = "Brakes"; break;
        case 4: repair.category = "Electrical"; break;
        case 5: repair.category = "Tires"; break;
        default: repair.category = "Other";
    }

    cout << "Cost: ";
    cin >> repair.cost;

    repairs.push_back(repair);

    cout << "\nRepair added successfully.\n";
}

void RepairManager::showRepairs() const
{
    cout << "\n========== REPAIRS ==========\n";

    if(repairs.empty())
    {
        cout << "No records.\n";
        return;
    }

    cout << fixed << setprecision(2);

    for(size_t i = 0; i < repairs.size(); i++)
    {
        cout
            << i + 1
            << ". Date: " << repairs[i].date
            << " | Mileage: " << repairs[i].mileage
            << " km | Category: " << repairs[i].category
            << " | Cost: " << repairs[i].cost
            << endl;
    }
}

double RepairManager::getTotalRepairCost() const
{
    double total = 0;

    for(const auto& repair : repairs)
    {
        total += repair.cost;
    }

    return total;
}

RepairRecord RepairManager::getMostExpensiveRepair() const
{
    RepairRecord result;

    if(repairs.empty())
        return result;

    result = repairs[0];

    for(const auto& repair : repairs)
    {
        if(repair.cost > result.cost)
        {
            result = repair;
        }
    }

    return result;
}

void RepairManager::saveToFile(const string& filename) const
{
    ofstream file(filename);

    if(!file.is_open())
        return;

    for(const auto& repair : repairs)
    {
        file
            << repair.date << ";"
            << repair.mileage << ";"
            << repair.category << ";"
            << repair.cost
            << endl;
    }

    file.close();
}

void RepairManager::loadFromFile(const string& filename)
{
    ifstream file(filename);

    if(!file.is_open())
        return;

    repairs.clear();

    RepairRecord repair;
    char separator;

    while(
        getline(file, repair.date, ';') &&
        file >> repair.mileage >> separator &&
        getline(file, repair.category, ';') &&
        file >> repair.cost
    )
    {
        file.ignore();

        repairs.push_back(repair);
    }

    file.close();
}

vector<RepairRecord> RepairManager::getRecords() const
{
    return repairs;
}

int RepairManager::getRecordCount() const
{
    return repairs.size();
}
void RepairManager::deleteRepair()
{
    if (repairs.empty())
    {
        cout << "No records.\n";
        return;
    }

    showRepairs();

    int index;

    cout << "\nRecord number to delete: ";
    cin >> index;

    if (index < 1 || index > (int)repairs.size())
    {
        cout << "Invalid index.\n";
        return;
    }

    repairs.erase(repairs.begin() + index - 1);

    cout << "Deleted successfully.\n";
}

void RepairManager::editRepair()
{
    if (repairs.empty())
    {
        cout << "No records.\n";
        return;
    }

    showRepairs();

    int index;

    cout << "\nRecord number to edit: ";
    cin >> index;

    if (index < 1 || index > (int)repairs.size())
    {
        cout << "Invalid index.\n";
        return;
    }

    RepairRecord& repair = repairs[index - 1];

    cout << "New date: ";
    cin >> repair.date;

    cout << "New mileage: ";
    cin >> repair.mileage;

    cout << "New category: ";
    cin >> repair.category;

    cout << "New cost: ";
    cin >> repair.cost;

    cout << "Updated successfully.\n";
}

void RepairManager::searchByDate(const string& date) const
{
    bool found = false;

    for (const auto& repair : repairs)
    {
        if (repair.date == date)
        {
            found = true;

            cout
                << repair.date
                << " | "
                << repair.category
                << " | "
                << repair.cost
                << endl;
        }
    }

    if (!found)
    {
        cout << "Nothing found.\n";
    }
}

void RepairManager::searchByCategory(
    const string& category
) const
{
    bool found = false;

    for (const auto& repair : repairs)
    {
        if (repair.category == category)
        {
            found = true;

            cout
                << repair.date
                << " | "
                << repair.mileage
                << " km | "
                << repair.cost
                << endl;
        }
    }

    if (!found)
    {
        cout << "Nothing found.\n";
    }
}

void RepairManager::sortByMileage()
{
    sort(
        repairs.begin(),
        repairs.end(),
        [](const RepairRecord& a,
           const RepairRecord& b)
        {
            return a.mileage < b.mileage;
        }
    );

    cout << "Sorted by mileage.\n";
}

void RepairManager::sortByCost()
{
    sort(
        repairs.begin(),
        repairs.end(),
        [](const RepairRecord& a,
           const RepairRecord& b)
        {
            return a.cost < b.cost;
        }
    );

    cout << "Sorted by cost.\n";
}
```
