#include "RepairCenter.h"

RepairCenter::RepairCenter()
{
    customers = new Customer[10];
    devices = new Device[10];
    jobs = new RepairJob[10];
    technicians = new Technician[10];

    customerCount = 0;
    deviceCount = 0;
    jobCount = 0;
    technicianCount = 0;

    customerCapacity = 10;
    deviceCapacity = 10;
    jobCapacity = 10;
    technicianCapacity = 10;
}

RepairCenter::~RepairCenter()
{
    delete[] customers;
    delete[] devices;
    delete[] jobs;
    delete[] technicians;
}

void RepairCenter::addDevice(Device device)
{
    

    if (deviceCount == deviceCapacity)
    {
        deviceCapacity = deviceCapacity * 2;

        Device* newDevices = new Device[deviceCapacity];

        for (int i = 0; i < deviceCount; i++)
        {
            newDevices[i] = devices[i];
        }

        delete[] devices;

        devices = newDevices;
    }

    devices[deviceCount] = device;
    deviceCount++;

}

void RepairCenter::displayDevices()
{
    for (int i = 0; i < deviceCount; i++)
    {
        devices[i].display();
        cout << endl;
    }
}

void RepairCenter::addJob(RepairJob job)
{
    if (jobCount == jobCapacity)
    {
        jobCapacity = jobCapacity * 2;

        RepairJob* newJobs = new RepairJob[jobCapacity];

        for (int i = 0; i < jobCount; i++)
        {
            newJobs[i] = jobs[i];
        }

        delete[] jobs;

        jobs = newJobs;
    }

    jobs[jobCount] = job;
    jobCount++;
}

void RepairCenter::createJob(int jobId, int deviceId, string problem)
{
    RepairJob job(jobId, deviceId, problem);

    job.estimateCost();

    addJob(job);

    cout << "Repair job created successfully." << endl;
}

void RepairCenter::displayJobs()
{
    for (int i = 0; i < jobCount; i++)
    {
        jobs[i].display();
        cout << endl;
    }
}

void RepairCenter::addTechnician(Technician technician)
{
    if (technicianCount == technicianCapacity)
    {
        technicianCapacity = technicianCapacity * 2;

        Technician* newTechnicians = new Technician[technicianCapacity];

        for (int i = 0; i < technicianCount; i++)
        {
            newTechnicians[i] = technicians[i];
        }

        delete[] technicians;

        technicians = newTechnicians;
    }

    technicians[technicianCount] = technician;
    technicianCount++;
}

void RepairCenter::displayTechnicians()
{
    for (int i = 0; i < technicianCount; i++)
    {
        technicians[i].display();
        cout << endl;
    }
}

void RepairCenter::searchDevice(int deviceId)
{
    for (int i = 0; i < deviceCount; i++)
    {
        if (devices[i].getDeviceId() == deviceId)
        {
            devices[i].display();
            return;
        }
    }

    cout << "Device not found." << endl;
}

void RepairCenter::searchCustomer(int customerId)
{
    for (int i = 0; i < customerCount; i++)
    {
        if (customers[i].getCustomerId() == customerId)
        {
            customers[i].display();
            return;
        }
    }

    cout << "Customer not found." << endl;
}

void RepairCenter::searchJob(int jobId)
{
    for (int i = 0; i < jobCount; i++)
    {
        if (jobs[i].getJobId() == jobId)
        {
            jobs[i].display();
            return;
        }
    }

    cout << "Job not found." << endl;
}

void RepairCenter::searchTechnician(int technicianId)
{
    for (int i = 0; i < technicianCount; i++)
    {
        if (technicians[i].getTechnicianId() == technicianId)
        {
            technicians[i].display();
            return;
        }
    }

    cout << "Technician not found." << endl;
}

void RepairCenter::updateCustomer(int customerId, string newName, string newPhone)
{
    for (int i = 0; i < customerCount; i++)
    {
        if (customers[i].getCustomerId() == customerId)
        {
            customers[i].updateCustomer(newName, newPhone);

            cout << "Customer updated successfully." << endl;
            return;
        }
    }

    cout << "Customer not found." << endl;
}

void RepairCenter::updateDevice(int deviceId, string newType, string newBrand, string newModel)
{
    for (int i = 0; i < deviceCount; i++)
    {
        if (devices[i].getDeviceId() == deviceId)
        {
            devices[i].updateDevice(newType, newBrand, newModel);

            cout << "Device updated successfully." << endl;
            return;
        }
    }

    cout << "Device not found." << endl;
}

void RepairCenter::updateJob(int jobId, string newProblem)
{
    for (int i = 0; i < jobCount; i++)
    {
        if (jobs[i].getJobId() == jobId)
        {
            jobs[i].updateJob(newProblem);

            cout << "Job updated successfully." << endl;
            return;
        }
    }

    cout << "Job not found." << endl;
}

void RepairCenter::updateTechnician(int technicianId, string newName, string newSkill)
{
    for (int i = 0; i < technicianCount; i++)
    {
        if (technicians[i].getTechnicianId() == technicianId)
        {
            technicians[i].updateTechnician(newName, newSkill);

            cout << "Technician updated successfully." << endl;
            return;
        }
    }

    cout << "Technician not found." << endl;
}

void RepairCenter::deleteCustomer(int customerId)
{
    for (int i = 0; i < customerCount; i++)
    {
        if (customers[i].getCustomerId() == customerId)
        {
            for (int j = i; j < customerCount - 1; j++)
            {
                customers[j] = customers[j + 1];
            }

            customerCount--;

            cout << "Customer deleted successfully." << endl;
            return;
        }
    }

    cout << "Customer not found." << endl;
}

void RepairCenter::deleteDevice(int deviceId)
{
    for (int i = 0; i < deviceCount; i++)
    {
        if (devices[i].getDeviceId() == deviceId)
        {
            for (int j = i; j < deviceCount - 1; j++)
            {
                devices[j] = devices[j + 1];
            }

            deviceCount--;

            cout << "Device deleted successfully." << endl;
            return;
        }
    }

    cout << "Device not found." << endl;
}

void RepairCenter::deleteJob(int jobId)
{
    for (int i = 0; i < jobCount; i++)
    {
        if (jobs[i].getJobId() == jobId)
        {
            for (int j = i; j < jobCount - 1; j++)
            {
                jobs[j] = jobs[j + 1];
            }

            jobCount--;

            cout << "Job deleted successfully." << endl;
            return;
        }
    }

    cout << "Job not found." << endl;
}

void RepairCenter::deleteTechnician(int technicianId)
{
    for (int i = 0; i < technicianCount; i++)
    {
        if (technicians[i].getTechnicianId() == technicianId)
        {
            for (int j = i; j < technicianCount - 1; j++)
            {
                technicians[j] = technicians[j + 1];
            }

            technicianCount--;

            cout << "Technician deleted successfully." << endl;
            return;
        }
    }

    cout << "Technician not found." << endl;
}

void RepairCenter::closeJob(int jobId)
{
    for (int i = 0; i < jobCount; i++)
    {
        if (jobs[i].getJobId() == jobId)
        {
            jobs[i].updateStatus("Completed");

            cout << "Job closed successfully." << endl;
            return;
        }
    }

    cout << "Job not found." << endl;
}

void RepairCenter::assignJobToTechnician(int technicianId, int jobId)
{
    for (int i = 0; i < technicianCount; i++)
    {
        if (technicians[i].getTechnicianId() == technicianId)
        {
            for (int j = 0; j < jobCount; j++)
            {
                if (jobs[j].getJobId() == jobId)
                {
                    technicians[i].assignJob();

                    cout << "Job " << jobId
                         << " assigned to Technician "
                         << technicianId << "." << endl;

                    return;
                }
            }

            cout << "Job not found." << endl;
            return;
        }
    }

    cout << "Technician not found." << endl;
}

void RepairCenter::addCustomer(Customer customer)
{
    if (customerCount == customerCapacity)
    {
        customerCapacity = customerCapacity * 2;

        Customer* newCustomers = new Customer[customerCapacity];

        for (int i = 0; i < customerCount; i++)
        {
            newCustomers[i] = customers[i];
        }

        delete[] customers;

        customers = newCustomers;
    }

    customers[customerCount] = customer;
    customerCount++;
}

void RepairCenter::displayCustomers()
{
    for (int i = 0; i < customerCount; i++)
    {
        customers[i].display();
        cout << endl;
    }
}

void RepairCenter::validateId(int id)
{
    if (id <= 0)
    {
        throw invalid_argument("ID must be greater than 0.");
    }
}

void RepairCenter::saveData()
{
    fileManager.saveCustomers(customers, customerCount);
    fileManager.saveDevices(devices, deviceCount);
    fileManager.saveJobs(jobs, jobCount);
    fileManager.saveTechnicians(technicians, technicianCount);

    cout << "Data saved successfully." << endl;
}

void RepairCenter::loadData()
{
    customerCount = 0;
    deviceCount = 0;
    jobCount = 0;
    technicianCount = 0;

    fileManager.loadCustomers(customers, customerCount);
    fileManager.loadDevices(devices, deviceCount);
    fileManager.loadJobs(jobs, jobCount);
    fileManager.loadTechnicians(technicians, technicianCount);

    cout << "Data loaded successfully." << endl;
}

void RepairCenter::runMenu()
{
    int choice;

    do
    {
        cout << "\n===== COMPUTER REPAIR MANAGEMENT =====" << endl;
        cout << "1. Add Record" << endl;
        cout << "2. Display Records" << endl;
        cout << "3. Search Record" << endl;
        cout << "4. Update Record" << endl;
        cout << "5. Delete Record" << endl;
        cout << "6. Main Transaction / Process" << endl;
        cout << "7. Report" << endl;
        cout << "8. Save / Load" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        try
        {
            switch (choice)
            {
            case 1:
            {
                int type;

                cout << "\n--- Add Record ---" << endl;
                cout << "1. Customer" << endl;
                cout << "2. Device" << endl;
                cout << "3. Repair Job" << endl;
                cout << "4. Technician" << endl;
                cout << "Enter choice: ";
                cin >> type;

                if (type == 1)
                {
                    int id;
                    string name;
                    string phone;

                    cout << "Enter Customer ID: ";
                    cin >> id;
                    validateId(id);

                    cout << "Enter Name: ";
                    cin.ignore();
                    getline(cin, name);

                    cout << "Enter Phone: ";
                    getline(cin, phone);

                    Customer customer(id, name, phone);
                    addCustomer(customer);

                    cout << "Customer added successfully." << endl;
                }
                else if (type == 2)
                {
                    int id;
                    string deviceType;
                    string brand;
                    string model;

                    cout << "Enter Device ID: ";
                    cin >> id;
                    validateId(id);

                    cout << "Enter Device Type: ";
                    cin >> deviceType;

                    cout << "Enter Brand: ";
                    cin >> brand;

                    cout << "Enter Model: ";
                    cin >> model;

                    Device device(id, deviceType, brand, model);
                    addDevice(device);

                    cout << "Device added successfully." << endl;
                }
                else if (type == 3)
                {
                    int jobId;
                    int deviceId;
                    string problem;

                    cout << "Enter Job ID: ";
                    cin >> jobId;
                    validateId(jobId);

                    cout << "Enter Device ID: ";
                    cin >> deviceId;
                    validateId(deviceId);

                    cout << "Enter Problem: ";
                    cin >> problem;

                    createJob(jobId, deviceId, problem);
                }
                else if (type == 4)
                {
                    int id;
                    string name;
                    string skill;

                    cout << "Enter Technician ID: ";
                    cin >> id;
                    validateId(id);

                    cout << "Enter Name: ";
                    cin.ignore();
                    getline(cin, name);

                    cout << "Enter Skill: ";
                    getline(cin, skill);

                    Technician technician(id, name, skill);
                    addTechnician(technician);

                    cout << "Technician added successfully." << endl;
                }
                else
                {
                    cout << "Invalid choice." << endl;
                }

                break;
            }

            case 2:
            {
                int type;

                cout << "\n--- Display Records ---" << endl;
                cout << "1. Customers" << endl;
                cout << "2. Devices" << endl;
                cout << "3. Repair Jobs" << endl;
                cout << "4. Technicians" << endl;
                cout << "5. Display All" << endl;
                cout << "Enter choice: ";
                cin >> type;

                if (type == 1)
                {
                    displayCustomers();
                }
                else if (type == 2)
                {
                    displayDevices();
                }
                else if (type == 3)
                {
                    displayJobs();
                }
                else if (type == 4)
                {
                    displayTechnicians();
                }
                else if (type == 5)
                {
                    cout << "\n--- Customers ---" << endl;
                    displayCustomers();

                    cout << "\n--- Devices ---" << endl;
                    displayDevices();

                    cout << "\n--- Repair Jobs ---" << endl;
                    displayJobs();

                    cout << "\n--- Technicians ---" << endl;
                    displayTechnicians();
                }
                else
                {
                    cout << "Invalid choice." << endl;
                }

                break;
            }

            case 3:
            {
                int type;
                int id;

                cout << "\n--- Search Record ---" << endl;
                cout << "1. Customer" << endl;
                cout << "2. Device" << endl;
                cout << "3. Repair Job" << endl;
                cout << "4. Technician" << endl;
                cout << "Enter choice: ";
                cin >> type;

                cout << "Enter ID: ";
                cin >> id;
                validateId(id);

                if (type == 1)
                {
                    searchCustomer(id);
                }
                else if (type == 2)
                {
                    searchDevice(id);
                }
                else if (type == 3)
                {
                    searchJob(id);
                }
                else if (type == 4)
                {
                    searchTechnician(id);
                }
                else
                {
                    cout << "Invalid choice." << endl;
                }

                break;
            }

            case 4:
            {
                int type;

                cout << "\n--- Update Record ---" << endl;
                cout << "1. Customer" << endl;
                cout << "2. Device" << endl;
                cout << "3. Repair Job" << endl;
                cout << "4. Technician" << endl;
                cout << "Enter choice: ";
                cin >> type;

                if (type == 1)
                {
                    int id;
                    string name;
                    string phone;

                    cout << "Enter Customer ID: ";
                    cin >> id;
                    validateId(id);

                    cout << "Enter New Name: ";
                    cin.ignore();
                    getline(cin, name);

                    cout << "Enter New Phone: ";
                    getline(cin, phone);

                    updateCustomer(id, name, phone);
                }
                else if (type == 2)
                {
                    int id;
                    string deviceType;
                    string brand;
                    string model;

                    cout << "Enter Device ID: ";
                    cin >> id;
                    validateId(id);

                    cout << "Enter New Device Type: ";
                    cin >> deviceType;

                    cout << "Enter New Brand: ";
                    cin >> brand;

                    cout << "Enter New Model: ";
                    cin >> model;

                    updateDevice(id, deviceType, brand, model);
                }
                else if (type == 3)
                {
                    int id;
                    string problem;

                    cout << "Enter Job ID: ";
                    cin >> id;
                    validateId(id);

                    cout << "Enter New Problem: ";
                    cin >> problem;

                    updateJob(id, problem);
                }
                else if (type == 4)
                {
                    int id;
                    string name;
                    string skill;

                    cout << "Enter Technician ID: ";
                    cin >> id;
                    validateId(id);

                    cout << "Enter New Name: ";
                    cin.ignore();
                    getline(cin, name);

                    cout << "Enter New Skill: ";
                    getline(cin, skill);

                    updateTechnician(id, name, skill);
                }
                else
                {
                    cout << "Invalid choice." << endl;
                }

                break;
            }

            case 5:
            {
                int type;
                int id;

                cout << "\n--- Delete Record ---" << endl;
                cout << "1. Customer" << endl;
                cout << "2. Device" << endl;
                cout << "3. Repair Job" << endl;
                cout << "4. Technician" << endl;
                cout << "Enter choice: ";
                cin >> type;

                cout << "Enter ID: ";
                cin >> id;
                validateId(id);

                if (type == 1)
                {
                    deleteCustomer(id);
                }
                else if (type == 2)
                {
                    deleteDevice(id);
                }
                else if (type == 3)
                {
                    deleteJob(id);
                }
                else if (type == 4)
                {
                    deleteTechnician(id);
                }
                else
                {
                    cout << "Invalid choice." << endl;
                }

                break;
            }

            case 6:
            {
                int transactionChoice;

                cout << "\n--- Main Transaction / Process ---" << endl;
                cout << "1. Create Repair Job" << endl;
                cout << "2. Assign Job to Technician" << endl;
                cout << "3. Close Repair Job" << endl;
                cout << "Enter choice: ";
                cin >> transactionChoice;

                if (transactionChoice == 1)
                {
                    int jobId;
                    int deviceId;
                    string problem;

                    cout << "Enter Job ID: ";
                    cin >> jobId;
                    validateId(jobId);

                    cout << "Enter Device ID: ";
                    cin >> deviceId;
                    validateId(deviceId);

                    cout << "Enter Problem: ";
                    cin >> problem;

                    createJob(jobId, deviceId, problem);
                }
                else if (transactionChoice == 2)
                {
                    int technicianId;
                    int jobId;

                    cout << "Enter Technician ID: ";
                    cin >> technicianId;
                    validateId(technicianId);

                    cout << "Enter Job ID: ";
                    cin >> jobId;
                    validateId(jobId);

                    assignJobToTechnician(technicianId, jobId);
                }
                else if (transactionChoice == 3)
                {
                    int jobId;

                    cout << "Enter Job ID: ";
                    cin >> jobId;
                    validateId(jobId);

                    closeJob(jobId);
                }
                else
                {
                    cout << "Invalid choice." << endl;
                }

                break;
            }

            case 7:
                showReport();
                break;

            case 8:
            {
                int saveLoadChoice;

                cout << "\n--- Save / Load ---" << endl;
                cout << "1. Save Data" << endl;
                cout << "2. Load Data" << endl;
                cout << "Enter choice: ";
                cin >> saveLoadChoice;

                if (saveLoadChoice == 1)
                {
                    saveData();
                }
                else if (saveLoadChoice == 2)
                {
                    loadData();
                }
                else
                {
                    cout << "Invalid choice." << endl;
                }

                break;
            }

            case 9:
                cout << "\nExiting program..." << endl;
                break;

            default:
                cout << "\nInvalid choice." << endl;
            }
        }
        catch (const invalid_argument& error)
        {
            cout << "\nError: " << error.what() << endl;
        }

    } while (choice != 9);
}

void RepairCenter::showReport()
{
    cout << "\n===== SYSTEM REPORT =====" << endl;

    cout << "Total Customers: " << customerCount << endl;
    cout << "Total Devices: " << deviceCount << endl;
    cout << "Total Repair Jobs: " << jobCount << endl;
    cout << "Total Technicians: " << technicianCount << endl;
}