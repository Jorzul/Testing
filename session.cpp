//
// Created by User on 7/12/2023.
//

#include "session.h"
#include <algorithm>

vector<string> Session::getVolunteersFromDepartment(string department) {
    vector<string> volunteers;

    for (auto vol : this->repository.getVolunteers())
        if (vol.getDepartmentName() == department)
            volunteers.push_back(vol.getVolunteer());

    sort(volunteers.begin(), volunteers.end());
    return volunteers;
}

vector<string> Session::getUnassigned() {
    vector<string> volunteers;

    for (auto vol : this->repository.getVolunteers())
        if (vol.getDepartmentName() == "Unassigned")
            volunteers.push_back(vol.getVolunteer());

    sort(volunteers.begin(), volunteers.end());
    return volunteers;
}

vector<pair<int, string>> Session::getStatistics() {
    return vector<pair<int, string>>();
}

vector<string> Session::getMostSuitable(string description) {
    return vector<string>();
}

void Session::addVolunteer(string name, string email, string interests, string department) {
    this->repository.addVolunteer(name, email, interests, department);
    this->notify();
}

void Session::assignVolunteer(string key, string department) {
    istringstream iss(key);
    const char sep = '|';
    string name, email, interests;
    getline(iss, name, sep);
    getline(iss, email, sep);
    getline(iss, interests, sep);

    for (int i = 0; i < this->repository.getVolunteers().size(); i++)
        if (this->repository.getVolunteers()[i].getVolunteer() == key)
        {
            this->repository.assignVolunteer(i, department);
            this->notify();
            break;
        }
}
