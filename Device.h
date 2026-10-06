#ifndef DEVICE_H
#define DEVICE_H

#include <iostream>
#include <string>
using namespace std;

class Device
{
private:
    int deviceId;
    string type;
    string brand;
    string model;

public:
    Device();
    Device(int deviceId, string type, string brand, string model);

    void display();
    int getDeviceId();
    string getType();
    string getBrand();
    string getModel();
    void updateDevice(string newType, string newBrand, string newModel);
};

#endif