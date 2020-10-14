//
// Created by Olga on 22/09/2020.
//

#include "Client.h"
#include "Mgr.h"

Client::Client(Mgr* manager) {
    mgr = manager;
}
void Client::run() {
    std::string call, name;
    while (true) {
        std:: cin >> call;
        if (call == "help") {
            std::cout << "help - displays this message" << '\n' 
                      << "start task_name - starts given task" << '\n'
                      << "stop task_name - stops given task" << '\n'
                      << "stat - displays statistics" << '\n'
                      << "quit - exiting timer" << '\n';
        } else if (call == "start") {
            std::cin >> name;
            if (mgr->create(name) != NULL) {
                mgr->start(name);
            } else {
                std::cout << "ERROR";
            }
        } else if (call == "stop") {
            std::cin >> name;
            mgr->stop(name);
        } else if (call == "stat") {
            mgr->print();
        } else if (call == "quit") {
            break;
        } else {
            std::cout << "OPTION UNKNOWN";
        }
    }
}