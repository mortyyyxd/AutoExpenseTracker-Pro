#include <iostream>

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
        cout << "\n";
        cout << "=================================\n";
        cout << "       CAR EXPENSE TRACKER\n";
        cout << "=================================\n";

        cout << "1. Add fuel record\n";
        cout << "2. Add repair record\n";
        cout << "3. Show fuel records\n";
        cout << "4. Show repair records\n";
        cout << "5. Show expense report\n";
        cout << "6. Save data\n";
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
                ReportManager::showFullReport(
                    fuelManager,
                    repairManager
                );
                break;

            case 6:

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
