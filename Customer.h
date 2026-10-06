#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Person.h"

class Customer : public Person
{
private:
    string phone;

public:
    Customer();
    Customer(int id, string name, string phone);

    void display()  override;
    int getCustomerId();
    string getName();
    string getPhone();
    void updateCustomer(string newName, string newPhone);
};
#endif