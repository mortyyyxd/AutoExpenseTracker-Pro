#ifndef REPORT_MANAGER_H
#define REPORT_MANAGER_H

#include "FuelManager.h"
#include "RepairManager.h"

class ReportManager
{
public:
    static void showFullReport(
        const FuelManager& fuelManager,
        const RepairManager& repairManager
    );
};

#endif
