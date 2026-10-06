#ifndef REPAIRJOB_H
#define REPAIRJOB_H

#include <iostream>
#include <string>
using namespace std;

class RepairJob
{
private:
    int jobId;
    int deviceId;
    string problem;
    double cost;
    string status;

public:
    RepairJob();
    RepairJob(int jobId, int deviceId, string problem);

    void estimateCost();
    void updateStatus(string newStatus);
    void updateJob(string newProblem);
    void display();
    int getJobId();
    int getDeviceId();
    string getProblem();
    double getCost();
    void setCost(double newCost);
    string getStatus();
};
#endif