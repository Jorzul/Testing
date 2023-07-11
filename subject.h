//
// Created by User on 7/12/2023.
//

#ifndef TESTING_SUBJECT_H
#define TESTING_SUBJECT_H

#include "observer.h"
#include <vector>
#include <memory>
using namespace std;

class Subject{
private:
    vector <unique_ptr<Observer> > observers;

public:
    void registerObserver(Observer *observer) { this->observers.emplace_back(observer); }
    void notify()
    {
        for (auto &obs : observers)
            obs->update();
    }
};

#endif //TESTING_SUBJECT_H
