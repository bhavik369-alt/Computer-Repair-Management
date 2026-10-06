#include "FileManager.h"
#include <fstream>

using namespace std;

void FileManager::saveCustomers(Customer* customers, int count)
{
    ofstream file("customers.txt");

    for (int i = 0; i < count; i++)
    {
        file << customers[i].getCustomerId() << endl;
        file << customers[i].getName() << endl;
        file << customers[i].getPhone() << endl;
    }

    file.close();
}

void FileManager::loadCustomers(Customer* customers, int& count)
{
    ifstream file("customers.txt");

    int id;
    string name;
    string phone;

    while (file >> id)
    {
        file.ignore();

        getline(file, name);
        getline(file, phone);

        customers[count] = Customer(id, name, phone);
        count++;
    }

    file.close();
}

void FileManager::saveDevices(Device* devices, int count)
{
    ofstream file("devices.txt");

    for (int i = 0; i < count; i++)
    {
        file << devices[i].getDeviceId() << endl;
        file << devices[i].getType() << endl;
        file << devices[i].getBrand() << endl;
        file << devices[i].getModel() << endl;
    }

    file.close();
}

void FileManager::loadDevices(Device* devices, int& count)
{
    ifstream file("devices.txt");

    int id;
    string type;
    string brand;
    string model;

    while (file >> id)
    {
        file.ignore();

        getline(file, type);
        getline(file, brand);
        getline(file, model);

        devices[count] = Device(id, type, brand, model);
        count++;
    }

    file.close();
}

void FileManager::saveJobs(RepairJob* jobs, int count)
{
    ofstream file("jobs.txt");

    for (int i = 0; i < count; i++)
    {
        file << jobs[i].getJobId() << endl;
        file << jobs[i].getDeviceId() << endl;
        file << jobs[i].getProblem() << endl;
        file << jobs[i].getCost() << endl;
        file << jobs[i].getStatus() << endl;
    }

    file.close();
}

void FileManager::loadJobs(RepairJob* jobs, int& count)
{
    ifstream file("jobs.txt");

    int jobId;
    int deviceId;
    string problem;
    double cost;
    string status;

    while (file >> jobId)
    {
        file >> deviceId;
        file.ignore();

        getline(file, problem);

        file >> cost;
        file.ignore();

        getline(file, status);

        RepairJob job(jobId, deviceId, problem);

        job.setCost(cost);
        job.updateStatus(status);

        jobs[count] = job;
        count++;
    }

    file.close();
}

void FileManager::saveTechnicians(Technician* technicians, int count)
{
    ofstream file("technicians.txt");

    for (int i = 0; i < count; i++)
    {
        file << technicians[i].getTechnicianId() << endl;
        file << technicians[i].getName() << endl;
        file << technicians[i].getSkill() << endl;
    }

    file.close();
}

void FileManager::loadTechnicians(Technician* technicians, int& count)
{
    ifstream file("technicians.txt");

    int id;
    string name;
    string skill;

    while (file >> id)
    {
        file.ignore();

        getline(file, name);
        getline(file, skill);

        technicians[count] = Technician(id, name, skill);
        count++;
    }

    file.close();
}