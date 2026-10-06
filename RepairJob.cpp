#include "RepairJob.h"

RepairJob::RepairJob()
{
    jobId = 0;
    deviceId = 0;
    problem = "";
    cost = 0;
    status = "Pending";
}

RepairJob::RepairJob(int jobId, int deviceId, string problem)
{
    this->jobId = jobId;
    this->deviceId = deviceId;
    this->problem = problem;
    cost = 0;
    status = "Pending";
}

void RepairJob::estimateCost()
{
    if (problem == "Screen")
    {
        cost = 3000;
    }
    else if (problem == "Battery")
    {
        cost = 1500;
    }
    else if (problem == "Keyboard")
    {
        cost = 1200;
    }
    else
    {
        cost = 1000;
    }
}

void RepairJob::updateStatus(string newStatus)
{
    status = newStatus;
}

void RepairJob::updateJob(string newProblem)
{
    problem = newProblem;
    estimateCost();
}

void RepairJob::display()
{
    cout << "Job ID: " << jobId << endl;
    cout << "Device ID: " << deviceId << endl;
    cout << "Problem: " << problem << endl;
    cout << "Cost: " << cost << endl;
    cout << "Status: " << status << endl;
}

int RepairJob::getJobId()
{
    return jobId;
}

int RepairJob::getDeviceId()
{
    return deviceId;
}

string RepairJob::getProblem()
{
    return problem;
}

double RepairJob::getCost()
{
    return cost;
}

void RepairJob::setCost(double newCost)
{
    cost = newCost;
}

string RepairJob::getStatus()
{
    return status;
}