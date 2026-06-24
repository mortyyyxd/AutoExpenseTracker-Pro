```cpp
#include <iostream>
#include <string>

#include "../include/FuelManager.h"
#include "../include/RepairManager.h"
#include "../include/ReportManager.h"

using namespace std;

int main()
{
    FuelManager fuelManager;
    RepairManager repairManager;

    fuelManager.loadFromFile("data/fuel.txt");
    repairManager.loadFromFile("data/repairs.txt");

    int choice;

    do
    {
        cout << "\n=====================================\n";
        cout << "        CAR EXPENSE TRACKER\n";
        cout << "=====================================\n";

        cout << "1. Add fuel\n";
        cout << "2. Add repair\n";

        cout << "3. Show fuels\n";
        cout << "4. Show repairs\n";

        cout << "5. Edit fuel\n";
        cout << "6. Delete fuel\n";

        cout << "7. Edit repair\n";
        cout << "8. Delete repair\n";

        cout << "9. Show report\n";
        cout << "10. Export report\n";

        cout << "11. Sort fuels by mileage\n";
        cout << "12. Sort fuels by cost\n";

        cout << "13. Sort repairs by mileage\n";
        cout << "14. Sort repairs by cost\n";

        cout << "15. Search fuel by date\n";
        cout << "16. Search repair by date\n";
        cout << "17. Search repair by category\n";

        cout << "18. Save data\n";

        cout << "0. Exit\n";

        cout << "\nChoice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                fuelManager.addFuel();
                break;

            case 2:
                repairManager.addRepair();
                break;

            case 3:
                fuelManager.showFuels();
                break;

            case 4:
                repairManager.showRepairs();
                break;

            case 5:
                fuelManager.editFuel();
                break;

            case 6:
                fuelManager.deleteFuel();
                break;

            case 7:
                repairManager.editRepair();
                break;

            case 8:
                repairManager.deleteRepair();
                break;

            case 9:
                ReportManager::showFullReport(
                    fuelManager,
                    repairManager
                );
                break;

            case 10:
                ReportManager::exportReportToFile(
                    fuelManager,
                    repairManager,
                    "report.txt"
                );
                break;

            case 11:
                fuelManager.sortByMileage();
                break;

            case 12:
                fuelManager.sortByCost();
                break;

            case 13:
                repairManager.sortByMileage();
                break;

            case 14:
                repairManager.sortByCost();
                break;

            case 15:
            {
                string date;

                cout << "Enter date: ";
                cin >> date;

                fuelManager.searchByDate(date);

                break;
            }

            case 16:
            {
                string date;

                cout << "Enter date: ";
                cin >> date;

                repairManager.searchByDate(date);

                break;
            }

            case 17:
            {
                string category;

                cout << "Enter category: ";
                cin >> category;

                repairManager.searchByCategory(
                    category
                );

                break;
            }

            case 18:

                fuelManager.saveToFile(
                    "data/fuel.txt"
                );

                repairManager.saveToFile(
                    "data/repairs.txt"
                );

                cout << "\nData saved.\n";

                break;

            case 0:

                fuelManager.saveToFile(
                    "data/fuel.txt"
                );

                repairManager.saveToFile(
                    "data/repairs.txt"
                );

                cout << "\nData saved automatically.\n";
                cout << "Goodbye!\n";

                break;

            default:
                cout << "\nInvalid option.\n";
        }

    } while(choice != 0);

    return 0;
}
```
