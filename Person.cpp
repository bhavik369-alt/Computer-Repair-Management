#include "Person.h"

Person::Person()
{
    id = 0;
    name = "";
}

Person::Person(int id, string name)
{
    this->id = id;
    this->name = name;
}

Person::~Person()
{
}