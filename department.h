//
// Created by User on 7/12/2023.
//

#ifndef TESTING_DEPARTMENT_H
#define TESTING_DEPARTMENT_H

#include <iostream>

using namespace std;

class Department {
private:
    string name, description;

public:
    Department(string name = "", string description = "") : name{name}, description{description} {};
    string getName() { return this->name; }
    string getDescription() { return this->description; }
};

#endif //TESTING_DEPARTMENT_H
