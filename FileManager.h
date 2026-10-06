#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "Customer.h"
#include "Device.h"
#include "RepairJob.h"
#include "Technician.h"

class FileManager
{
public:
    void saveCustomers(Customer* customers, int count);
    void loadCustomers(Customer* customers, int& count);
    void saveDevices(Device* devices, int count);
    void loadDevices(Device* devices, int& count);
    void saveJobs(RepairJob* jobs, int count);
    void loadJobs(RepairJob* jobs, int& count);
    void saveTechnicians(Technician* technicians, int count);
    void loadTechnicians(Technician* technicians, int& count);
};

#endif