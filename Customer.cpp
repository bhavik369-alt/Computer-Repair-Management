#include "Customer.h"

Customer::Customer()
{
    id = 0;
    name = "";
    phone = "";
}

Customer::Customer(int id, string name, string phone)
{
    this->id = id;
    this->name = name;
    this->phone = phone;
}

void Customer::display() 
{
    cout << "Customer ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Phone: " << phone << endl;
}

int Customer::getCustomerId()
{
    return id;
}

string Customer::getName()
{
    return name;
}

string Customer::getPhone()
{
    return phone;
}

void Customer::updateCustomer(string newName, string newPhone)
{
    name = newName;
    phone = newPhone;
}