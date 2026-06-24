```cpp
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
    // Основні функції
    void addRepair();
    void showRepairs() const;

    // Файли
    void saveToFile(const string& filename) const;
    void loadFromFile(const string& filename);

    // Статистика
    double getTotalRepairCost() const;

    RepairRecord getMostExpensiveRepair() const;

    vector<RepairRecord> getRecords() const;

    int getRecordCount() const;

    // Нові функції
    void editRepair();
    void deleteRepair();

    void searchByDate(const string& date) const;
    void searchByCategory(const string& category) const;

    void sortByMileage();
    void sortByCost();
};

#endif
```
