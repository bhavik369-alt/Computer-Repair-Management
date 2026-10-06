#ifndef TECHNICIAN_H
#define TECHNICIAN_H

#include "Person.h"

class Technician : public Person
{
private:
    string skill;

public:
    Technician();
    Technician(int id, string name, string skill);

    void display()  override;
    void assignJob();
    int getTechnicianId();
    string getName();
    string getSkill();
    void updateTechnician(string newName, string newSkill);
};
#endif