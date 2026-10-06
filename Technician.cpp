#include "Technician.h"

Technician::Technician()
{
    id = 0;
    name = "";
    skill = "";
}

Technician::Technician(int id, string name, string skill)
{
    this->id = id;
    this->name = name;
    this->skill = skill;
}

void Technician::display() 
{
    cout << "Technician ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Skill: " << skill << endl;
}

void Technician::assignJob()
{
    cout << "Job assigned to technician: " << name << endl;
}

int Technician::getTechnicianId()
{
    return id;
}

string Technician::getName()
{
    return name;
}

string Technician::getSkill()
{
    return skill;
}

void Technician::updateTechnician(string newName, string newSkill)
{
    name = newName;
    skill = newSkill;
}