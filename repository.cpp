//
// Created by User on 7/12/2023.
//

#include "repository.h"

Repository::~Repository() {
    ofstream output(this->volunteersFilePath);

    for (auto vol : this->volunteers)
        output << vol.getName() << "|" << vol.getEmail() << "|" << vol.getInterests() << "|" << vol.getDepartmentName() << "\n";
}

void Repository::loadRepo() {
    ifstream input(this->departmentsFilePath);
    const char sep = '|';
    string row, name, description;

    while (getline(input, row))
    {
        istringstream iss(row);
        getline(iss, name, sep);
        getline(iss, description, sep);
        this->departments.emplace_back(name, description);
    }
    input.close();

    input = ifstream (this->volunteersFilePath);
    string email, interests, departmentName;

    while (getline(input, row))
    {
        istringstream iss1(row);
        getline(iss1, name, sep);
        getline(iss1, email, sep);
        getline(iss1, interests, sep);
        getline(iss1, departmentName, sep);
        this->volunteers.emplace_back(name, email, interests, departmentName);
    }
}

void Repository::addVolunteer(string name, string email, string interests, string department) {
    if (name == "")
        throw std::runtime_error("Empty name!");
    if (email == "")
        throw std::runtime_error("Empty email!");

    this->volunteers.emplace_back(name, email, interests, department);
}

void Repository::assignVolunteer(int position, string department) {
    this->volunteers[position].setDepartment(department);
}
