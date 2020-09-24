//
// Created by Olga on 22/09/2020.
//

#include "Client.h"
#include "Mgr.h"

Client::Client(Mgr* manager) {
    mgr = manager;
}
void Client::run() {
    string command, name;
    while (true) {
        cin >> command;
        if (command == "quit") break;
        else if (command == "help") {
            std::cout << "* help - displays this message\n"
                         "* start task_name - starts given task\n"
                         "* stop task_name - stops given task\n"
                         "* stat all - displays statistics\n"
                         "* stat name - displays stat for given task or error if task with such name does not exists\n"
                         "* quit - exiting timer" << endl;
        }
        else if (command == "start") {
            cin >> name;
            mgr->create(name);
            mgr->start(name);
        }
        else if (command == "stop") {
            cin >> name;
            mgr->stop(name);
        }
        else if (command == "stat") {
            cin >> name;
            mgr->print();
        }
        else cout << "Option unknown, may use help" << endl;
    }

}