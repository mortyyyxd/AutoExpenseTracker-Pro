```cpp
#include <algorithm>
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
