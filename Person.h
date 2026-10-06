#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
using namespace std;

class Person
{
protected:
    int id;
    string name;

public:
    Person();
    Person(int id, string name);

    virtual void display() = 0;

    virtual ~Person();
};

#endif