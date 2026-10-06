#include "Device.h"

Device::Device()
{
    deviceId = 0;
    type = "";
    brand = "";
    model = "";
}

Device::Device(int deviceId, string type, string brand, string model)
{
    this->deviceId = deviceId;
    this->type = type;
    this->brand = brand;
    this->model = model;
}

void Device::display()
{
    cout << "Device ID: " << deviceId << endl;
    cout << "Type: " << type << endl;
    cout << "Brand: " << brand << endl;
    cout << "Model: " << model << endl;
}

int Device::getDeviceId()
{
    return deviceId;
}

void Device::updateDevice(string newType, string newBrand, string newModel)
{
    type = newType;
    brand = newBrand;
    model = newModel;
}

string Device::getType()
{
    return type;
}

string Device::getBrand()
{
    return brand;
}

string Device::getModel()
{
    return model;
}