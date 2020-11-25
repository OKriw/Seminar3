//
// Created by Olga on 22/09/2020.
//

#include "Client.h"
#include "Mgr.h"

Client::Client(Mgr* manager) {
    mgr = manager;
}
void Client::run() {
    string command, name, old_name;
    while (true) {
        cin >> command;
        if (command == "quit") break;
        else if (command == "help") {
            std::cout << "* help - displays this message\n"
                         "* start task_name - starts given task (if you have another task running this task will be stopped)\n"
                         "* stop task_name - stops given task\n"
                         "* stat task_name/all - display statistics for given task or for all tasks\n"
                         "* rename new_name old_name - renames the given task. Make sure task is not running.\n"
                         "* clear task_name  - clears the timer of the given task\n"
                         "* delete task_name - delete given task\n"
                         "* dump - dumps all tasks info into tasks_dump.txt\n"
                         "* quit - exiting timer" << endl;
        }
        else if (command == "start") {
            cin >> name;
            if (mgr->create(name) != nullptr) mgr->start(name);
        }
        else if (command == "stop") {
            cin >> name;
            mgr->stop();
        }
        else if (command == "stat") {
            cin >> name;
            mgr->print(name);
        }
        else if (command == "rename") {
            cin >> name >> old_name;
            mgr->ren(name, old_name);
        }
        else if (command == "clear") {
            cin >> name;
            mgr->clear(name);
        }
        else if (command == "delete") {
            cin >> name;
            mgr->mdelete(name);
        }
        else if (command == "dump") {
            mgr->dump();
        }
        else cout << "Option unknown, may use help" << endl;
    }

}