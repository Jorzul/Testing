//
// Created by User on 7/12/2023.
//

#ifndef TESTING_VOLUNTEER_H
#define TESTING_VOLUNTEER_H

#include <iostream>
#include <vector>
using namespace std;

class Volunteer {
private:
    string name, email, departmentName, interests;

public:
    Volunteer(string name = "", string email = "", string interests = "", string departmentName = "") : name{name}, email{email}, interests{interests}, departmentName{departmentName} {};
    void setDepartment(string department) { this->departmentName = department; }
    string getName() { return this->name; }
    string getEmail() { return this->email; }
    string getDepartmentName() { return this->departmentName; }
    string getInterests() { return this->interests; }
    string getVolunteer()
    {
        return this->name + "|" + this->email + "|" + this->interests;
    }
};

#endif //TESTING_VOLUNTEER_H
