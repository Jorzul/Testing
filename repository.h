//
// Created by User on 7/12/2023.
//

#ifndef TESTING_REPOSITORY_H
#define TESTING_REPOSITORY_H

#include "volunteer.h"
#include "department.h"
#include <fstream>
#include <sstream>

class Repository {
private:
    string departmentsFilePath, volunteersFilePath;
    vector <Department> departments;
    vector <Volunteer> volunteers;

public:
    Repository()
    {
        this->departmentsFilePath = "../departments.txt";
        this->volunteersFilePath = "../volunteers.txt";
        this->loadRepo();
    }

    ~Repository();

    void loadRepo();
    void addVolunteer(string name, string email, string interests, string department);
    void assignVolunteer(int position, string department);

    vector <Department> &getDepartments() { return this->departments; }
    vector <Volunteer> &getVolunteers() { return this->volunteers; }
};

#endif //TESTING_REPOSITORY_H
