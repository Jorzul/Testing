//
// Created by User on 7/12/2023.
//
#include <QApplication>
#include "repository.h"
#include "window.h"
#include "session.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    Repository repo;
    Session session(repo);

    for (auto department : repo.getDepartments())
    {
        auto *window = new Window(session, department);
        window->show();
    }

    return QApplication::exec();
}
