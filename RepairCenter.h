#include "Customer.h"
#include "Device.h"
#include "RepairJob.h"
#include "Technician.h"
#include "FileManager.h"
#include <stdexcept>

class RepairCenter
{
private:
    Customer* customers;
    Device* devices;
    RepairJob* jobs;
    Technician* technicians;
    FileManager fileManager;

    int customerCount;
    int deviceCount;
    int jobCount;
    int technicianCount;

    int customerCapacity;
    int deviceCapacity;
    int jobCapacity;
    int technicianCapacity;

public:
    RepairCenter();
    ~RepairCenter();

    void addCustomer(Customer customer);
    void addDevice(Device device);
    void addJob(RepairJob job);
    void createJob(int jobId, int deviceId, string problem);
    void addTechnician(Technician technician);

    void displayCustomers();
    void displayDevices();
    void displayJobs();
    void displayTechnicians();

    void searchDevice(int deviceId);
    void searchCustomer(int customerId);
    void searchJob(int jobId);
    void searchTechnician(int technicianId);

    void updateCustomer(int customerId, string newName, string newPhone);
    void updateDevice(int deviceId, string newType, string newBrand, string newModel);
    void updateJob(int jobId, string newProblem);
    void updateTechnician(int technicianId, string newName, string newSkill);

    void closeJob(int jobId);
    void assignJobToTechnician(int technicianId, int jobId);

    void deleteCustomer(int customerId);
    void deleteDevice(int deviceId);
    void deleteJob(int jobId);
    void deleteTechnician(int technicianId);

    void validateId(int id);

    void saveData();
    void loadData();

    void runMenu();
    void showReport();
};